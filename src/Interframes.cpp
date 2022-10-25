#include "../include/Interframes.h"
#include <iostream>

void InterframesPrediction(YUV& video, Predictor& predictor)
{
    vector<PredictionBlock>& blocks = predictor.getBlockList();
    Frame* referenceFrame = video.getFrame(0);
    Frame* nextFrame = video.getFrame(1);
    const int blockSize = 8;
    double timeElapsed;
    // #pragma omp parallel shared(video, predictor, blocks, referenceFrame, nextFrame)
    {
    // #pragma omp for
    for (auto block = blocks.begin(); block != blocks.end(); block++)
    {
        // cout << "Block " << addressof(*block) << " starting...\n";
        Frame::ByteMatrix nextFrameBlock;
        nextFrameBlock = nextFrame->getBlock(block->xPos, block->yPos, 
                      block->xPos + block->wSize, block->xPos + block->hSize);
        // #pragma omp for 
        // timeElapsed = omp_get_wtime();
        // cout << "(Block " << addressof(*block) << ") For loop starting...\n";
        for (int i = 0; i < video.getHeader().height - blockSize + 1; i++) {
            // cout << "test\n i " << i << '\n';
            // #pragma omp for
            for (int j = 0; j < video.getHeader().width - blockSize + 1; j++) {
                bool blockFound = true;
                for (int k = 0; k < blockSize; k++) {
                    for (int l = 0; l < blockSize; l++) {
                        if (referenceFrame->pixelDifferent(i+k, j+l, nextFrameBlock[k][l], 25)) {
                            blockFound = false;
                            break;
                        }
                    }
                    if (!blockFound)
                        break;
                }
                if (blockFound) {
                    // #pragma omp critical (blockSave)
                    predictor.constructBlockVector(i, j, addressof(*block));
                }
            }
        }
        // cout << "(Block " << addressof(*block) << ") For loop end!\n";
        // cout << "Time elapsed: " << omp_get_wtime() - timeElapsed << "\n\n";
    }

    }
}