#include <string>
using namespace std;

struct YUVHeader {
    int width;
    int height;
    
    YUVHeader(int w, int h);
    YUVHeader() = default;
};