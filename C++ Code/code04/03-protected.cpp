#include <iostream>
using namespace std;
 
class Rectangle {
    protected:
    //private: // ERROR
        double width;
        double height;
};
 
class Square:Rectangle { // Square is the derived class.
    public:
        void set_size(double s);
        double get_size();
        double get_area();
};

void Square::set_size(double s){
    width = s;
    height = s;
}

double Square::get_size(){
    return width;
}

double Square::get_area(){
    return width * height;
}
 
int main() {
   Square sq;

   sq.set_size(5.0);
   cout << "Area of sq = " << sq.get_area() << endl;
 
   return 0;
}
