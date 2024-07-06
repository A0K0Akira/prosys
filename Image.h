#pragma once
#include"File.h"

class Image : public File{
private:
    int width;
    int height;
public:
    Image(string n, string e, int width, int height);
    int getHeight() const;
    int getWidth() const;
    void setDimensions(int width, int height);
    void details() const override;
    void op() override;
};
