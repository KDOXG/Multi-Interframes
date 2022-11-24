#include "../include/Interframes.h"
#include <iostream>

void InterframesPrediction(YUV& video, Predictor& predictor)
{
    // OpenMP setup
    omp_set_num_threads(4);
    omp_set_nested(true);

    // MPI setup
    int worldSize, myRank;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &worldSize);
    MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

    if (myRank == 0)
    {
        cout << "Reference frame is frame 0\n";
        cout << "Total blocks: " << predictor.getBlockList().size() << '\n';
    }

    // Application setup
    Frame* referenceFrame = video.getFrame(0);
    Frame* nextFrame;

    // vector<Frame*> *frameList = new vector<Frame*>;
    // frameList->push_back(nextFrame);

    for (int it = myRank; it < 20; it+=worldSize)
    {
        nextFrame = video.getFrame(it+1);
        blockFind(referenceFrame, nextFrame, predictor, video.getHeader());
        cout << "Predicted " << predictor.getResultList().size() << " blocks for frame " << it+1 << '\n';
        predictor.cleanPredicted();
    }



    // delete(frameList);
    MPI_Finalize();
}

void blockFind(Frame* referenceFrame, Frame* nextFrame, Predictor& predictor, const VideoHeader& header)
{
    vector<PredictionBlock>& blocks = predictor.getBlockList();
    const int blockSize = 8;
    #pragma omp parallel shared(predictor, header, referenceFrame, nextFrame)
    {
        // for (auto nextFrame : frameList)
        // {
        #pragma omp for schedule(dynamic, 4)
        for (auto block = blocks.begin(); block < blocks.end(); block++)
        {
            bool blockFound = false;
            Frame::ByteMatrix nextFrameBlock;
            nextFrameBlock = nextFrame->getBlock(block->xPos, block->yPos,
                block->xPos + block->wSize, block->yPos + block->hSize);
            for (int i = 0; i < header.height - blockSize + 1; i++) {
                for (int j = 0; j < header.width - blockSize + 1; j++) {
                    blockFound = true;
                    for (int k = 0; k < blockSize; k++) {
                        for (int l = 0; l < blockSize; l++) {
                            if (referenceFrame->pixelDifferent(i + k, j + l, nextFrameBlock[k][l], 25)) {
                                blockFound = false;
                                break;
                            }
                        }
                        if (!blockFound)
                            break;
                    }
                    if (blockFound) {
                        #pragma omp critical (blockSave)
                        predictor.constructBlockVector(i, j, addressof(*block), referenceFrame);
                        break;
                    }
                }
                if (blockFound)
                    break;
            }
        }
        // }
    }
}