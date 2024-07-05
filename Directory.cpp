#include "Directory.h"

Directory::Directory(string n, Directory *p) : name(n), parent(p){

}

void Directory::print() const {
    cout << "---Files: " << endl;
    for(int i = 0; i < (int)files.size(); ++i)
        cout << files[i]->getName() + '.' + files[i]->getExtension() << endl;
    cout << "---Directories: " << endl;
    for(int i = 0; i < (int)directories.size(); ++i)
        cout << directories[i]->getName() << endl;
}

string Directory::getName() const {
    return name;
}

void Directory::setName(string n) {
    name = n;
}

void Directory::addDirectory(string n) {
    if(directoryContain(n)){
        cout << "Directory with the given name already exists" << endl;
        return;
    }
    directories.push_back(new Directory(n, this));
}

void Directory::addTxt(string n, string e) {
    if(fileContain(n)){
        cout << "File with the given name already exists" << endl;
        return;
    }
    files.push_back(new Txt(n, e));
}

void Directory::addCpp(string n, string e) {
    if(fileContain(n)){
        cout << "File with the given name already exists" << endl;
        return;
    }
    files.push_back(new Cpp(n, e));
}

void Directory::addAudio(string n, string e, int d, int s) {
    if(fileContain(n)){
        cout << "File with the given name already exists" << endl;
        return;
    }
    files.push_back(new AudioFile(n, e, d, s));
}

void Directory::addImage(string n, string e, int width, int height) {
    if(fileContain(n)){
        cout << "File with the given name already exists" << endl;
        return;
    }
    files.push_back(new Image(n, e, width, height));
}

void Directory::addExecutable(string n, string e, string plat, bool ex) {
    if(fileContain(n)){
        cout << "File with the given name already exists" << endl;
        return;
    }
    files.push_back(new Executable(n, e, plat, ex));
}

Directory::~Directory() {
    for(int i = 0; i < (int)files.size(); ++i)
        delete files[i];
    for(int i = 0; i < (int)directories.size(); ++i)
        delete directories[i];
}

void Directory::removeDirectory(string n) {
    for(int i = 0; i < (int)directories.size(); ++i)
        if(directories[i]->getName() == n){
            delete directories[i];
            for(int j = i; j < (int)directories.size()-1; ++j)
                directories[j] = directories[j+1];
            directories.pop_back();
            break;
        }
}

void Directory::removeFile(string n) {
    for(int i = 0; i < (int)files.size(); ++i)
        if(files[i]->getName() == n){
            delete files[i];
            for(int j = i; j < (int)files.size()-1; ++j)
                files[j] = files[j+1];
            files.pop_back();
            break;
        }
}

Directory *Directory::getParent() const {
    return parent;
}

bool Directory::fileContain(string n) const{
    for(int i = 0; i < (int)files.size(); ++i)
        if(files[i]->getName() == n)
            return true;
    return false;
}

bool Directory::directoryContain(string n) const{
    for(int i = 0; i < (int)directories.size(); ++i)
        if(directories[i]->getName() == n)
            return true;
    return false;
}


void Directory::op() const {
    for(int i = 0; i < (int)files.size(); ++i)
        cout << i << " " << files[i]->getName() + '.' + files[i]->getExtension() << endl;
    cout << "Enter the index of the file on which you want to perform operation\n";
    int idx;
    cin >> idx;
    if(idx>=0&&idx<(int)files.size())
        files[idx]->op();
}

Directory *Directory::getDirectory() const {
    for(int i = 0; i < (int)directories.size(); ++i)
        cout << i << " " << directories[i]->getName() << endl;
    cout << "Enter the index of the directory\n";
    int idx;
    cin >> idx;
    if(idx>=0&&idx<(int)directories.size())
        return directories[idx];
    return nullptr;
}

void Directory::clear() {
    for(int i = 0; i < (int)directories.size(); ++i)
        clear_(directories[i]);
    directories.clear();
    files.clear();
}

void Directory::clear_(Directory *root) {
    for(int i = 0; i < (int)root->directories.size(); ++i)
        clear_(root->directories[i]);
    root->directories.clear();
    for(int i = 0; i < (int)root->files.size(); ++i)
        delete root->files[i];
    root->files.clear();
    delete root;
}

File *Directory::getFile() const {
    for(int i = 0; i < (int)files.size(); ++i)
        cout << i << " " << files[i]->getName() + '.' + files[i]->getExtension() << endl;
    cout << "Enter the index of the file\n";
    int idx;
    cin >> idx;
    if(idx>=0&&idx<(int)files.size())
        return files[idx];
    return nullptr;
}

