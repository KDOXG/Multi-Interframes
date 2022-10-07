#include "../include/Frame.h"

Frame::Frame(vector<uint8_t>* image, YUVHeader &header):
    sample(image),
    width(header.width),
    height(header.height) {}

Frame::~Frame()
{
    delete(sample);
}