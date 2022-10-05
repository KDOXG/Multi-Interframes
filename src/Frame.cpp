#include "../include/Frame.h"

Frame::Frame(int w, int h)
{
    sample = new vector<int>();
    width = w;
    height = h;
}
Frame::~Frame()
{
    delete(sample);
}