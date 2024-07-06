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
