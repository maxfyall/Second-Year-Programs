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

        friend void printrect(Rectangle r);
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
    width = w;
    height = h;
}

Rectangle::Rectangle(const Rectangle &r){
    width = r.width;
    height = r.height;
}

Rectangle::~Rectangle(){
}

void printrect(Rectangle r){
    cout << "Area of " << r.width << "x" << r.height <<
        " rectangle = " << r.get_area() << endl;
}

int main() {
    Rectangle rect1(3.0, 2.0);
    Rectangle rect2(4.0, 5.0);
    printrect(rect1);
    printrect(rect2);
 
    return 0;
}
