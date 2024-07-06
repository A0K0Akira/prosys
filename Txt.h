#pragma once
#include"File.h"

class Txt : public File{
public:
    Txt(string n, string e);
    void details() const override;
    void op() override;
};


