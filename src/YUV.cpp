#include "../include/YUV.h"
#include <iostream>
#include <algorithm>

YUV::YUV(string filename)
{
    videoFile = new ifstream(filename, ios::binary);
    if (videoFile->fail())
        throw exception();
    header = createHeader(filename);
    videoBytes = new vector<uint8_t>();
    char reading;
    while (!videoFile->eof())
    {
        videoFile->read(&reading, 1);
        videoBytes->push_back(reading);
    }
    videoFile->close();
    frames = new vector<Frame*>();
}

YUV::~YUV()
{
    delete(videoFile);
    delete(videoBytes);
    // for(auto it = frames->begin(); it != frames->end(); it++) delete(*it);
    // for (auto it : *frames)
    //     delete(it);
    for_each(frames->begin(), frames->end(), [](auto it) {delete(it);});
    delete(frames);
}

YUVHeader YUV::createHeader(string filename) const
{
    int wPos = filename.rfind('_') + 1;
    int wLen = filename.rfind('x') - filename.rfind('_');
    int hPos = filename.rfind('x') + 1;
    int hLen = filename.rfind('.') - filename.rfind('x');
    int w = stoi(filename.substr(wPos, wLen));
    int h = stoi(filename.substr(hPos, hLen));
    return YUVHeader(w,h);
}

const YUVHeader& YUV::getHeader() const
{
    return header;
}

Frame* YUV::getFrame(const int n)
{
    while (frames->size() <= n) frames->push_back(NULL);
    if (frames->at(n) == NULL)
    {
        auto frameBegin = this->videoBytes->begin();
        frameBegin += n * header.width * header.height / 2;   //2 * w * h / 4
        auto frameEnd = frameBegin + header.width * header.height;

        Frame* frame = new Frame(new vector<uint8_t>(frameBegin, frameEnd), header);
        frames->at(n) = frame;
    }
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