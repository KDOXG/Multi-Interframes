#ifndef YUV_H
#define YUV_H

#include "YUVHeader.h"
#include "Frame.h"
#include "lib.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class YUV {
    YUVHeader header;

    ifstream *videoFile;
    vector<uint8_t> *videoBytes;

    vector<Frame*> *frames;

    YUVHeader createHeader(string filename) const;

public:
    YUV(string filename);
    ~YUV();
    void DEBUG() const;
    Frame* getFrame(const int n);
    Frame* loadNextFrame();
};

#endif