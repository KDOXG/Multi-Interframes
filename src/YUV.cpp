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
    videoFile->close();
    frames = new vector<Frame*>;
}

YUV::~YUV()
{
    delete(videoFile);
    delete(videoBytes);
    delete(frames);
}

Frame* YUV::getFrame(const int n) const
{
    return frames->at(n);
}

Frame* YUV::loadNextFrame()
{
    auto frameBegin = this->videoBytes->begin();
    frameBegin += frames->size() * header.width * header.height / 2;   //2 * w * h / 4
    auto frameEnd = frameBegin + header.width * header.height;

    Frame* frame = new Frame(new vector<uint8_t>(frameBegin, frameEnd), header);
    frames->push_back(frame);
    return frame;
}

void YUV::DEBUG() const
{
    cout << "YUVHeader header;\n";
    cout << "\twidth " << header.width << '\n';
    cout << "\theight " << header.height << '\n';
    cout << "ifstream *videoFile;\nvector<uint8_t> *videoBytes;\n";
    cout << "\tsize " << videoBytes->size() << '\n';
    cout << "vector<Frame*> *frames;\n";
    cout << "\tframe quantity " << frames->size() << '\n';
}