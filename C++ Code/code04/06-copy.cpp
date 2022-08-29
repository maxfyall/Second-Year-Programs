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
        Rectangle(const Rectangle &r);
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

Rectangle::Rectangle(const Rectangle &r){
    cout << "Copying rectangle" << endl;
    width = r.width;
    height = r.height;
}

Rectangle::~Rectangle(){
    cout << "Destroying a rectangle" << endl;
}

void printrect(Rectangle r){
    cout << "Area of " << r.get_width() << "x" << r.get_height() <<
        " rectangle = " << r.get_area() << endl;
}

int main() {
    Rectangle rect1(3.0, 2.0);
    Rectangle rect2(rect1);

    cout << "Area of " << rect1.get_width() << "x" << rect1.get_height() << 
        " rectangle = " << rect1.get_area() << endl;
    printrect(rect2);
 
    return 0;
}
