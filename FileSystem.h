#pragma once
#include"Directory.h"

class FileSystem {
private:
    Directory *curr;
public:
    FileSystem();
    ~FileSystem();
    void work();
};


// 3 0 3 1 3 2 5 0 3 0 3 1 3 0 6 5 1 3 0 3 1 3 2 4 1 11 6 4 1 11 4 2 22 windows y 5 1 4 1 11 5 0 4 5 11 11 1 1