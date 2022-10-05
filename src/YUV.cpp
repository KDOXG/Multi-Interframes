#include "../include/YUV.h"
#include <iostream>

YUV::YUV(string filename)
{
    videoFile = new ifstream(filename, ios::binary);
    // if (!videoFile)
    //     throw error;
    int wPos = filename.rfind('_') + 1;
    int wLen = filename.rfind('x') - filename.rfind('_');
    int hPos = filename.rfind('x') + 1;
    int hLen = filename.rfind('.') - filename.rfind('x');
    int w = stoi(filename.substr(wPos, wLen));
    int h = stoi(filename.substr(hPos, hLen));
    header = YUVHeader(w,h);
    videoBytes = new vector<uint8_t>();
    char reading;
    while (!videoFile->eof())
    {
        videoFile->read(&reading, 1);
        videoBytes->push_back(reading);
    }
    frames = new vector<Frame*>;
    itFrame = 0;
}

YUV::~YUV()
{
    delete(videoFile);
    delete(videoBytes);
    delete(frames);
}

void YUV::DEBUG()
{
    cout << "YUVHeader header;\n";
    cout << "\twidth " << header.width << '\n';
    cout << "\theight " << header.height << '\n';
    cout << "ifstream *videoFile;\nvector<uint8_t> *videoBytes;\n";
    cout << "\tsize " << videoBytes->size() << '\n';
    cout << "vector<Frame*> *frames;\nint itFrame;\n";
    cout << "\tframe iterator " << itFrame << '\n';
}