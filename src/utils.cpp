#include "../include/utils.h"

long GetFileSize(const char* filename)
{
    struct stat stat_buf;
    int size = stat(filename, &stat_buf);
    return size == 0 ? stat_buf.st_size : -1;
}