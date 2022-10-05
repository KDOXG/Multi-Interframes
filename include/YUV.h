#include "YUVHeader.h"
#include "Frame.h"
#include "lib.h"
#include <vector>
#include <fstream>
using namespace std;

class YUV {
    YUVHeader header;

    ifstream *videoFile;
    vector<uint8_t> *videoBytes;

    vector<Frame*> *frames;
    int itFrame;

public:
    YUV(string filename = "template");
    ~YUV();
    void DEBUG();
    int getFrame(int n);
    int getNextFrame();
};