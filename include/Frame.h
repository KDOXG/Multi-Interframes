#include <vector>
#include <string>
using namespace std;

class Frame {
    vector<int> *sample;
    int width;
    int height;

public:
    Frame(int w, int h);
    ~Frame();
};