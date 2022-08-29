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
        Rectangle(double w, double h);
        ~Rectangle();
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

Rectangle::Rectangle(double w, double h){
    cout << "Creating a rectangle" << endl;
    width = w;
    height = h;
}

Rectangle::~Rectangle(){
    cout << "Destroying a rectangle" << endl;
}

void new_rectangle(){
    Rectangle rect(1.0, 1.0);
    cout << "Area of " << rect.get_width() << "x" << rect.get_height() <<
        " rectangle = " << rect.get_area() << endl;
}

int main() {
    new_rectangle();

    Rectangle rect1(3.0, 2.0);
    Rectangle rect2(5.0, 2.0);

    cout << "Area of " << rect1.get_width() << "x" << rect1.get_height() << 
        " rectangle = " << rect1.get_area() << endl;
    cout << "Area of " << rect2.get_width() << "x" << rect2.get_height() <<
        " rectangle = " << rect2.get_area() << endl;
 
    return 0;
}
