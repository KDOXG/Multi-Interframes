#include "../include/Frame.h"

Frame::Frame(vector<uint8_t>* sample, YUVHeader &header):
    sample(sample),
    width(header.width),
    height(header.height)
    {
        image = new ByteMatrix;
        for (auto it = sample->begin(); it != sample->end(); it += width)
            image->emplace_back(it, it + width);
    }

Frame::~Frame()
{
    delete(sample);
    delete(image);
}

Frame::ByteMatrix Frame::getBlock(const int x, const int y, const int w, const int h) const
{
    ByteMatrix result;
    if (!(x < w && y < h && w < width && h < height))
        return result;
    for (auto it = image->begin()+y; it != image->begin()+h; it++)
    {
        result.emplace_back(it->begin() + x, it->begin() + w);
    }
    return result;
}

bool Frame::pixelDifferent(int x, int y, uint8_t v, int weight = 0) const
{
    return abs(image->at(x).at(y) - v) > weight;
}

const Frame::ByteMatrix& Frame::getFrame() const
{
    return *image;
}