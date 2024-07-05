#pragma once
#include"Image.h"
#include"Executable.h"
#include"AudioFile.h"
#include"Cpp.h"
#include"Txt.h"
#include<vector>
class Directory {
private:
    vector<Directory *> directories;
    vector<File *> files;
    Directory *parent;
    string name;
    void clear_(Directory *root);
public:
    Directory(string n, Directory *p);
    ~Directory();
    string getName() const;
    void setName(string n);
    void print() const;
    bool fileContain(string n) const;
    bool directoryContain(string n) const;
    void addDirectory(string n);
    void addTxt(string n, string e);
    void addCpp(string n, string e);
    void addAudio(string n, string e, int d, int s);
    void addImage(string n, string e, int width, int height);
    void addExecutable(string n, string e, string plat, bool ex);
    void removeDirectory(string n);
    void removeFile(string n);
    Directory* getParent() const;
    void op() const;
    Directory* getDirectory() const;
    File* getFile() const;
    void clear();
};
