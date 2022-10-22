#pragma once

#include "VideoHeader.h"

struct YUVHeader: public VideoHeader {
    YUVHeader(int w, int h);
    YUVHeader() = default;
};