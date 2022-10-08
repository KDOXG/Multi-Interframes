#ifndef VIDEOHEADER_H
#define VIDEOHEADER_H

struct VideoHeader {
    int width;
    int height;
    
    VideoHeader(int w, int h);
    VideoHeader() = default;
};

#endif