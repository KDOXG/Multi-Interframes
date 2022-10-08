#ifndef YUVHEADER_H
#define YUVHEADER_H

#include "VideoHeader.h"

struct YUVHeader: public VideoHeader {
    YUVHeader(int w, int h);
    YUVHeader() = default;
};

#endif