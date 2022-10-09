#include "include/YUV.h"
#include "include/Predictor.h"
#include "include/Interframes.h"
#include <iostream>
using namespace std;

int main()
{
    YUV *yuv = new YUV("video_converted_640x360.yuv");
    Predictor *predictor = new Predictor(yuv->getHeader(), 8);
    yuv->loadNextFrame();
    yuv->loadNextFrame();

    InterframesPrediction(*yuv, *predictor);

    DEBUG(*yuv, *predictor);
    delete(yuv);
    delete(predictor);
    return 0;
}