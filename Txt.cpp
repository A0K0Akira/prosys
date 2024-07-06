#include "Txt.h"

Txt::Txt(string n, string e) : File(n, "txt"){
}

void Txt::details() const {
    cout << "Name: " << name << endl;
    cout << "Extension: " << extension << endl;
}

void Txt::op(){
    int c;
    cout << "Enter 1 to know the details of the file\n"
            "Enter 2 to edit the content of the file\n";
    cin >> c;
    if(c == 1)
        details();
    else if(c == 2)
        readData();
}
