#include "Image.h"

Image::Image(string n, string e, int width, int height) : File(n, e), width(width), height(height){
}

void Image::setDimensions(int width, int height) {
    this->width = width;
    this->height = height;
}

int Image::getHeight() const {
    return height;
}

int Image::getWidth() const {
    return width;
}

void Image::details() const {
    cout << "Name: " << name << endl;
    cout << "Format: " << extension << endl;
    cout << "Height: " << height << endl;
    cout << "Width: " << width << endl;
}

void Image::op(){
    int c;
    cout << "Enter 1 to know the details of the file\n"
            "Enter 2 to resize the image file\n";
    cin >> c;
    if(c == 1)
        details();
    else if(c == 2){
        int h, w;
        cout << "Enter height: ";
        cin >> h;
        cout << "\nEnter width: ";
        cin >> w;
        cout << endl;
        setDimensions(w, h);
    }
}

