#include "include/log.h"
#include "include/YUV.h"
#include "include/Predictor.h"
#include "include/Interframes.h"
#include <iostream>
using namespace std;

int main()
{
    double timeElapsed;
    YUV *yuv = NULL;
    Predictor *predictor = NULL;

    timeElapsed = omp_get_wtime();
    cout << "Instancing video class...\n";
    try {
    yuv = new YUV("video_converted_640x360.yuv");
    }
    catch (exception) {
        cout << "Error opening video file! Shutting down...\n";
        return -1;
    }
    cout << "Time elapsed: " << omp_get_wtime() - timeElapsed << '\n';

    cout << "Instancing predictor class...\n";
    predictor = new Predictor(yuv->getHeader(), 8);
    yuv->loadNextFrame();
    yuv->loadNextFrame();

    timeElapsed = omp_get_wtime();
    cout << "Running interframes prediction...\n";
    InterframesPrediction(*yuv, *predictor);
    cout << "Time elapsed: " << omp_get_wtime() - timeElapsed << '\n';
    
    cout << '\n';
    LOG(*yuv, *predictor);
    delete(yuv);
    delete(predictor);
    return 0;
}