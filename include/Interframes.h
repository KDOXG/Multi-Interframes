#ifndef INTERFRAMES_H
#define INTERFRAMES_H

//now it's time to omp
#include "YUV.h"
#include "Predictor.h"
#include <omp.h>

void InterframesPrediction(YUV& video, Predictor& predictor);

#endif