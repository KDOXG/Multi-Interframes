#pragma once

#include "YUVHeader.h"
#include "lib.h"
#include <vector>
#include <cstdlib>
using namespace std;

class Frame {
public:
    typedef vector<vector<uint8_t>> ByteMatrix;

    Frame(vector<uint8_t>* sample, YUVHeader& header);
    ~Frame();
    ByteMatrix getBlock(const int x, const int y, const int w, const int h) const;
    const ByteMatrix& getFrame() const;
    bool pixelDifferent(int x, int y, uint8_t v, int weight) const;

private:
    vector<uint8_t> *sample;
    int width;
    int height;
    ByteMatrix *image;
};