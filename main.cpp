#include "include/YUV.h"
#include "include/Interframes.h"

int main()
{
    YUV *yuv = new YUV("video_converted_640x360.yuv");
    yuv->loadNextFrame();
    yuv->loadNextFrame();
    interframesPrediction(*yuv);
    yuv->DEBUG();
    delete(yuv);
    return 0;
}