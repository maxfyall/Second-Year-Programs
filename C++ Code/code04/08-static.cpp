#include <iostream>
using namespace std;
 
class Rectangle {
    private:
        double width;
        double height;
    public:
        static int object_count;

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
    width = w;
    height = h;
    object_count++;
}

Rectangle::~Rectangle(){
    object_count--;
}

int Rectangle::object_count = 0;

int main() {
    Rectangle rect1(1.0, 1.0);
    Rectangle rect2(1.0, 1.0);

    cout << "We have " << Rectangle::object_count << " rectangles." << endl;

    Rectangle rect3(1.0, 1.0);
    Rectangle rect4(1.0, 1.0);

    cout << "We have " << Rectangle::object_count << " rectangles." << endl;
 
    return 0;
}
