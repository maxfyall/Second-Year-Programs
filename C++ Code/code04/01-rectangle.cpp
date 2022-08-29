#include <iostream>
using namespace std;
 
class Rectangle {
    public:
        double width;
        double height;
 
        void scale(double factor);
        double get_area(){
            return width * height;
        }
};

void Rectangle::scale(double factor){
    width *= factor;
    height *= factor;
}
 
int main() {
    Rectangle rect;
    rect.width = 3.0;
    rect.height = 2.0;

    cout << "Area of rect: " << rect.get_area() << endl;
    rect.scale(2.0);
    cout << "Area of rect: " << rect.get_area() << endl;
 
    return 0;
}
