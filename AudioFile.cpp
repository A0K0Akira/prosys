#include "AudioFile.h"

AudioFile::AudioFile(string n, string e, int duration, int sampleRate) : File(n, e), duration(duration), sampleRate(sampleRate) {

}

int AudioFile::getDuration() const {
    return duration;
}

void AudioFile::setDuration(int duration) {
    this->duration = duration;
}

int AudioFile::getSampleRate() const {
    return sampleRate;
}

void AudioFile::setSampleRate(int sampleRate) {
    this->sampleRate = sampleRate;
}

void AudioFile::details() const {
    cout << "Name: " << name << endl;
    cout << "Format: " << extension << endl;
    cout << "Duration: " << duration << endl;
    cout << "Sample Rate: " << sampleRate << endl;
}

void AudioFile::op(){
    int c;
    cout << "Enter 1 to know the details of the file\n"
            "Enter 2 to set the duration of the audio file\n"
            "Enter 3 to set the sample rate of the audio file\n";
    cin >> c;
    if(c == 1)
        this->details();
    else if(c == 2){
        cout << "Enter the duration to set" << endl;
        int d;
        cin >> d;
        this->setDuration(d);
    }
    else if(c == 3){
        int s;
        cout << "Enter the sample rate to set" << endl;
        cin >> s;
        this->setSampleRate(s);
    }
}
