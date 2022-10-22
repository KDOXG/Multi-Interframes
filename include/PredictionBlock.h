#pragma once

struct PredictionBlock {
    int wSize;
    int hSize;
    int xPos;
    int yPos;

    PredictionBlock(const int& wSize, const int& hSize, const int& xPos, const int& yPos);
    PredictionBlock() = default;
};