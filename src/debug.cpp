#include "../include/YUV.h"
#include "../include/Predictor.h"
#include <iostream>
using namespace std;

void DEBUG(YUV& yuv, Predictor& predictor)
{
    cout << "YUV yuv;\n\n";
    cout << "YUVHeader header;\n";
    cout << "\twidth " << yuv.header.width << '\n';
    cout << "\theight " << yuv.header.height << '\n';
    cout << "ifstream *videoFile;\nvector<uint8_t> *videoBytes;\n";
    cout << "\tsize " << yuv.videoBytes->size() << '\n';
    cout << "vector<Frame*> *frames;\n";
    cout << "\tframe quantity " << yuv.frames->size() << '\n';
    cout << "\tframe[3] " << (int*) (yuv.getFrame(3)) << '\n';
    cout << '\n';
    cout << "Predictor predictor;\n\n";
    cout << "vector<PredictionBlock> *blockList;\n";
    cout << "\tprediction blocks quantity " << predictor.blockList->size() << '\n';
    cout << "vector<PredictionVector> *resultList;\n";
    cout << "\tprediction vectors quantity " << predictor.resultList->size() << '\n';
}
