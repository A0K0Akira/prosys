#pragma once
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class File {
protected:
    string name;
    string extension;
    string data;
    int size;
public:
    File(string n, string e);
    virtual ~File() = default;
    string getName() const;
    void setName(string& name_);
    int getSize() const;
    string getData() const;
    void readData();
    string getExtension() const;
    virtual void details() const = 0;
    virtual void op() = 0;
};


