#pragma once

//now it's time to omp
#include "YUV.h"
#include "Predictor.h"
#include "Frame.h"
#include <type_traits>
#include <cstdlib>
#include <omp.h>

void InterframesPrediction(YUV& video, Predictor& predictor);