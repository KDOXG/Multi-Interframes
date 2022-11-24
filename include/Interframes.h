#pragma once

#include "YUV.h"
#include "Predictor.h"
#include "Frame.h"
#include <type_traits>
#include <cstdlib>
#include <omp.h>
#ifdef MPI
#include <mpi.h>
#endif

void InterframesPrediction(YUV& video, Predictor& predictor);
void blockFind(Frame* referenceFrame, Frame* nextFrame, Predictor& predictor, const VideoHeader& header);
// void blockFind(Frame* referenceFrame, vector<Frame*>& frameList, Predictor& predictor, const VideoHeader& header);