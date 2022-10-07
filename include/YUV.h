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

public:
    YUV(string filename);
    ~YUV();
    void DEBUG() const;
    Frame* getFrame(const int n) const;
    Frame* loadNextFrame();
};