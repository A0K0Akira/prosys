#include "FileSystem.h"

FileSystem::FileSystem() {
    curr = new Directory("Root", nullptr);
}

void FileSystem::work() {
    cout << "\t\t\t\t*** Welcome to the File Management System Project ***" << endl;
    while(true){
        cout << endl;
        int c;
        cout << "*** Currently you are at " << curr->getName() << " directory ***" << endl << endl;
        cout << "Enter 1 if you want to print all the directories and files in the current directory\n"
                "Enter 2 if you want to change the name of the current directory\n"
                "Enter 3 if you want to create a new directory\n"
                "Enter 4 if you want to create a file\n"
                "Enter 5 if you want to enter in another directory\n"
                "Enter 6 if you want to get back to the previous directory\n"
                "Enter 7 if you want to delete all the files and directories\n"
                "Enter 8 to remove a directory\n"
                "Enter 9 to remove a file\n"
                "Enter 10 to perform operation on a file\n"
                "Enter any other number to terminate the file management system\n";
        cin >> c;
        if(c == 1)
            curr->print();
        else if(c == 2){
            string s;
            cout << "Enter the name\n";
            cin >> s;
            curr->setName(s);
        }
        else if(c == 3){
            string s;
            cout << "Enter the name of the new directory\n";
            cin >> s;
            curr->addDirectory(s);
        }
        else if(c == 4){
            int cc;
            cout << "Enter 1 if you want to add .txt file\n"
                    "Enter 2 if you want to add .exe file\n"
                    "Enter 3 if you want to add .cpp file\n"
                    "Enter 4 if you want to add image file\n"
                    "Enter 5 if you want to add audio file\n";
            cin >> cc;
            if(cc == 1){
                string n;
                cout << "Enter the name of the txt file.\n";
                cin >> n;
                curr->addTxt(n, "txt");
            }
            else if(cc == 2){
                string n, p;
                bool ex = false;
                cout << "Enter the name of the exe file.\n";
                cin >> n;
                cout << "Enter the platform of the exe file(Windows, Linux or MacOs).\n";
                cin >> p;
                char exec;
                cout << "Enter y/Y if the file is executable.\n";
                cin >> exec;
                ex = (exec=='Y' || exec=='y');
                curr->addExecutable(n, "exe", p, ex);
            }
            else if(cc == 3){
                string n;
                cout << "Enter the name of the cpp file.\n";
                cin >> n;
                curr->addCpp(n, "cpp");
            }
            else if(cc == 4){
                string n, e;
                cout << "Enter the name of the image file.\n";
                cin >> n;
                cout << "Enter the format of the image file.\n";
                cin >> e;
                int h, w;
                cout << "Enter the height of the image.\n";
                cin >> h;
                cout << "Enter the width of the image.\n";
                cin >> h;
                curr->addImage(n, e, h, w);
            }
            else if(cc == 5){
                string n, e;
                int d, s;
                cout << "Enter the name of the audio file.\n";
                cin >> n;
                cout << "Enter the format of the audio file.\n";
                cin >> e;
                cout << "Enter the duration of audio file.\n";
                cin >> d;
                cout << "Enter the sample rate of the audio file.\n";
                cin >> s;
                curr->addAudio(n, e, d, s);
            }
        }
        else if(c == 5){
            Directory *next = curr->getDirectory();
            if(next)
                curr = next;
        }
        else if(c == 6){
            if(curr->getParent())
                curr = curr->getParent();
            else
                cout << "You are at the root directory\n";
        }
        else if(c == 7){
            while(curr->getParent())
                curr = curr->getParent();
            curr->clear();
        }
        else if(c == 8){
            Directory *d = curr->getDirectory();
            if(d)
                curr->removeDirectory(d->getName());
        }
        else if(c == 9){
            File *f = curr->getFile();
            if(f)
                curr->removeFile(f->getName());
        }
        else if(c == 10)
            curr->op();
        else{
            while(curr->getParent())
                curr = curr->getParent();
            curr->clear();
            break;
        }
    }
}

FileSystem::~FileSystem() {
    delete curr;
}
