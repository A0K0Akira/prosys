#pragma once
#include"File.h"

class AudioFile : public File {
private:
    int duration;
    int sampleRate;
public:
    AudioFile(string n, string e, int duration, int sampleRate);
    int getDuration() const;
    void setDuration(int duration);
    int getSampleRate() const;
    void setSampleRate(int sampleRate);
    void details() const override;
    void op() override;
};

