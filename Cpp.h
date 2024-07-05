#pragma once
#include"File.h"
class Cpp : public File{
public:
    Cpp(string n, string e);
    void details() const override;
    void op() override;
};
