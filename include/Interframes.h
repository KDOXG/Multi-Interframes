//now it's time to omp
#include "YUV.h"
#include "PredictionBlock.h"
#include <omp.h>

void interframesPrediction(YUV& video);