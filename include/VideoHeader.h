#pragma once

struct VideoHeader {
    int width;
    int height;
    
    VideoHeader(int w, int h);
    VideoHeader() = default;
};