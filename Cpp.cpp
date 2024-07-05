#include "Cpp.h"

Cpp::Cpp(string n, string e) : File(n, "cpp") {
}

void Cpp::details() const {
    cout << "Name: " << name << endl;
    cout << "Extension: " << extension << endl;
}

void Cpp::op() {
    int c;
    cout << "Enter 1 to know the details of the file\n"
            "Enter 2 to edit the content of the file\n";
    cin >> c;
    if(c == 1)
        this->details();
    else if(c == 2)
        this->readData();
}

