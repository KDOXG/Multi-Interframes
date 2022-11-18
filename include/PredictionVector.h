#pragma once

#include "PredictionBlock.h"
#include "Frame.h"
#include <array>
using namespace std;

struct PredictionVector {
    array<int, 4> vectorPos;
    PredictionBlock* block;
    Frame* referenceFrame;

    PredictionVector(const int& x, const int& y, PredictionBlock* block, Frame* referenceFrame);
    PredictionVector() = default;
};