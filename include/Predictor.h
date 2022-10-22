#pragma once

#include "VideoHeader.h"
#include "Frame.h"
#include "PredictionBlock.h"
#include "PredictionVector.h"
#include "YUV.h"
#include <vector>
using namespace std;

class YUV;

class Predictor
{
    vector<PredictionBlock> *blockList;
    vector<PredictionVector> *resultList;

public:
    Predictor(const VideoHeader& header, int blockSize);
    ~Predictor();

    void constructBlockVector(int x, int y, PredictionBlock* block);
    const vector<PredictionVector>& getResultList() const;

    friend void DEBUG(YUV&, Predictor&);
};