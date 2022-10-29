#include "../include/log.h"
#include "../include/YUV.h"
#include "../include/Predictor.h"
#include <iostream>
using namespace std;

void LOG(YUV& yuv, Predictor& predictor)
{
    cout << "All informations:\n";
    cout << '\n';
    cout << "YUV yuv;\n";
    cout << '\n';
    cout << "YUVHeader header;\n";
    cout << "\twidth " << yuv.header.width << '\n';
    cout << "\theight " << yuv.header.height << '\n';
    cout << "ifstream *videoFile;\nvector<uint8_t> *videoBytes;\n";
    cout << "\tsize " << yuv.videoBytes->size() << '\n';
    cout << "vector<Frame*> *frames;\n";
    cout << "\tframe quantity " << yuv.frames->size() << '\n';
    cout << "\tframe[3] " << (int*) (yuv.getFrame(3)) << '\n';
    cout << '\n';
    cout << "Predictor predictor;\n";
    cout << '\n';
    cout << "vector<PredictionBlock> *blockList;\n";
    cout << "\tprediction blocks quantity " << predictor.blockList->size() << '\n';
    cout << "vector<PredictionVector> *resultList;\n";
    cout << "\tprediction vectors quantity " << predictor.resultList->size() << '\n';
    cout << '\n';
    cout << "OpenMP configurations\n";
    cout << "\tomp_set_num_threads(4);\n";
    cout << "\tomp_set_nested(true);\n";
    cout << '\n';
    cout << "Parallel operations\n";
    cout << "\tDefining main parallel region:\n";
    cout << "\t#pragma omp parallel shared(video, predictor, blocks, referenceFrame, nextFrame)\n";
    cout << "\tInside parallel:\n";
    cout << "\t\t#pragma omp for schedule(dynamic, 4)\n";
    cout << "\t\tfor (auto block = blocks.begin(); block < blocks.end(); block++)\n";
    cout << "\t\tInside for:\n";
    cout << "\t\t\t#pragma omp critical (blockSave)\n";
    cout << "\t\t\tpredictor.constructBlockVector(i, j, addressof(*block));\n";
    cout << "\n";
    cout << "(Please refer to the source code at src/Interframes.cpp::InterframesPrediction to understand more about the implementation)\n";
    cout << "\n";
    
}
