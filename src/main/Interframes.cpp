#include "../../include/Interframes.h"
#include <iostream>

void InterframesPrediction(YUV& video, Predictor& predictor)
{
    // OpenMP setup
    omp_set_num_threads(4);
    omp_set_nested(true);

    // Application setup
    Frame* referenceFrame = video.getFrame(0);
    Frame* nextFrame = video.getFrame(1);

    // vector<Frame*> *frameList = new vector<Frame*>;
    // frameList->push_back(nextFrame);

    blockFind(referenceFrame, nextFrame, predictor, video.getHeader());

    // delete(frameList);
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