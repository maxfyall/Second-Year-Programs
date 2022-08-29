#include <iostream>
using namespace std;
 
class Rectangle {
    private:
        double width;
        double height;
    public:
        void set_width(double w);
        double get_width();
        void set_height(double h);
        double get_height();

        double get_area();
};

void Rectangle::set_width(double w){
    width = w;
}

double Rectangle::get_width(){
    return width;
}

void Rectangle::set_height(double h){
    height = h;
}

double Rectangle::get_height(){
    return height;
}

double Rectangle::get_area(){
    return width * height;
}

int main() {
    Rectangle rect;
    // rect.width = 3.0; // ERROR
    rect.set_width(3.0);
    rect.set_height(2.0);

    cout << "Area of " << rect.get_width() << "x" << rect.get_height() << 
        " rectangle = " << rect.get_area() << endl;
 
    return 0;
}
