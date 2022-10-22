#pragma once

#include "PredictionBlock.h"
#include <array>
using namespace std;

struct PredictionVector {
    array<int, 4> vectorPos;
    PredictionBlock* block;

    PredictionVector(const int& x, const int& y, PredictionBlock* block);
    PredictionVector() = default;
};