#include "File.h"

File::File(string n, string e) :size(0), name(n), extension(e) {
}

string File::getName() const {
    return name;
}

void File::setName(string& name_) {
    name = name_;
}

string File::getData() const {
    return data;
}

int File::getSize() const {
    return size;
}

void File::readData() {
    cout << "Enter the data you want to write ***(Enter $ to stop reading data)***\n";
    string curr;
    getline(cin, curr, '$');
    int c;
    cout << "Enter 1 if you want to append the data\nEnter 2 if you want to overwrite the data\n";
    cin >> c;
    if(c==1)
        data += curr;
    else
        data = curr;
    size = sizeof(data);
}

string File::getExtension() const {
    return extension;
}


