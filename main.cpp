#include "include/YUV.h"
#include "include/Predictor.h"
#include "include/Interframes.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Instancing video class...\n";
    YUV *yuv = new YUV("video_converted_640x360.yuv");
    cout << "Instancing predictor class...\n";
    Predictor *predictor = new Predictor(yuv->getHeader(), 8);
    yuv->loadNextFrame();
    yuv->loadNextFrame();
    cout << "Running interframes prediction...\n\n";
    InterframesPrediction(*yuv, *predictor);
    DEBUG(*yuv, *predictor);
    delete(yuv);
    delete(predictor);
    return 0;
}