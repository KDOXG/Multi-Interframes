#include "include/YUV.h"
#include "include/Interframes.h"
#include <iostream>
using namespace std;

int main()
{
    YUV *yuv = new YUV("video_converted_640x360.yuv");
    yuv->loadNextFrame();
    yuv->loadNextFrame();
    interframesPrediction(*yuv);
    yuv->DEBUG();
    cout << "\tframe[3] " << (int*) yuv->getFrame(3) << '\n';
    delete(yuv);
    return 0;
}