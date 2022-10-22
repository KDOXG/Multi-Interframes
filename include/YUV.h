#pragma once

#include "YUVHeader.h"
#include "Frame.h"
#include "lib.h"
#include "Predictor.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Predictor;

class YUV {
    YUVHeader header;

    ifstream *videoFile;
    vector<uint8_t> *videoBytes;

    vector<Frame*> *frames;

    YUVHeader createHeader(string filename) const;

public:
    YUV(string filename);
    ~YUV();
    YUVHeader& getHeader();
    Frame* getFrame(const int n);
    Frame* loadNextFrame();

    friend void DEBUG(YUV&, Predictor&);
};