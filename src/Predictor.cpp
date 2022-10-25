#include "../include/Predictor.h"
#include <iostream>
using namespace std;

Predictor::Predictor(const VideoHeader& header, int blockSize)
{
    blockList = new vector<PredictionBlock>();
    for (int i = 0; i < header.width; i+= blockSize)
        for (int j = 0; j < header.height; j+= blockSize)
            blockList->emplace_back(blockSize, blockSize, i, j);
    resultList = new vector<PredictionVector>();
}

Predictor::~Predictor()
{
    delete(blockList);
    delete(resultList);
}

void Predictor::constructBlockVector(int x, int y, PredictionBlock* block)
{
    resultList->emplace_back(x, y, block);
}

vector<PredictionBlock>& Predictor::getBlockList() const
{
    return *blockList;
}

const vector<PredictionVector>& Predictor::getResultList() const
{
    return *resultList;
}