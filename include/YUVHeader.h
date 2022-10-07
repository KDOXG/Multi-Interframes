#ifndef YUVHEADER_H
#define YUVHEADER_H

#include <string>
using namespace std;

struct YUVHeader {
    int width;
    int height;
    
    YUVHeader(int w, int h);
    YUVHeader() = default;
};

#endif