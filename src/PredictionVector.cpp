#include "../include/PredictionVector.h"

PredictionVector::PredictionVector(const int& x, const int& y, PredictionBlock* block, Frame* referenceFrame)
{
    this->block = block;
    vectorPos[0] = x;
    vectorPos[1] = y;
    vectorPos[2] = block->xPos;
    vectorPos[3] = block->yPos;
    this->referenceFrame = referenceFrame;
}