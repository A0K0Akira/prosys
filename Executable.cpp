
#include "Executable.h"

Executable::Executable(string n, string e, string plat, bool ex) : File(n, e), platform(plat), isExecutable(ex){

}

void Executable::setPlatform(const string& platform) {
    this->platform = platform;
}

bool Executable::checkExecutable() const {
    return isExecutable;
}

string Executable::getPlatform() const {
    return platform;
}

void Executable::details() const {
    cout << "Name: " << name << endl;
    cout << "Extension: " << extension << endl;
    cout << "Platform: " << platform << endl;
    cout << "Is Executable: " << (isExecutable?"YES":"NO") << endl;
}

void Executable::op(){
    int c;
    cout << "Enter 1 to know the details of the file\n"
            "Enter 2 to set the platform of the executable file\n";
    cin >> c;
    if(c == 1)
        this->details();
    else if(c == 2){
        cout << "Enter the name of the platform: ";
        string s;
        cin >> s;
        this->setPlatform(s);
    }
}