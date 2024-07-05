#pragma once
#include"File.h"

class Executable : public File {
private:
    string platform;
    bool isExecutable;
public:
    Executable(string n, string e, string plat, bool ex);
    void setPlatform(const std::string& platform);
    bool checkExecutable() const;
    string getPlatform() const;
    void details() const override;
    void op();
};

