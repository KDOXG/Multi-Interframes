#ifndef FRAME_H
#define FRAME_H

#include "YUVHeader.h"
#include "lib.h"
#include <vector>
#include <string>
using namespace std;

class Frame {
    vector<uint8_t> *sample;
    int width;
    int height;

public:
    Frame(vector<uint8_t>* image, YUVHeader& header);
    ~Frame();
};

#endif