#include "include/YUV.h"

int main()
{
    YUV *yuv = new YUV("video_converted_640x360.yuv");
    yuv->DEBUG();
    delete(yuv);
    return 0;
}