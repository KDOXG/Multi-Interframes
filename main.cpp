#include "include/YUV.h"
#include "include/Predictor.h"
#include "include/Interframes.h"
#include <iostream>
using namespace std;

int main()
{
    double timeElapsed;
    cout << "Instancing video class...\n";
    YUV *yuv = NULL;
    try {
    yuv = new YUV("video_converted_640x360.yuv");
    }
    catch (exception) {
        cout << "Error opening video file! Shutting down...\n";
        return 0;
    }
    cout << "Instancing predictor class...\n";
    Predictor *predictor = new Predictor(yuv->getHeader(), 8);
    yuv->loadNextFrame();
    yuv->loadNextFrame();
    cout << "Running interframes prediction...\n";
    timeElapsed = omp_get_wtime();
    // InterframesPrediction(*yuv, *predictor);
    cout << "Time elapsed: " << omp_get_wtime() - timeElapsed << '\n';
    cout << '\n';
    DEBUG(*yuv, *predictor);
    delete(yuv);
    delete(predictor);
    return 0;
}