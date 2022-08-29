#include <iostream>
using namespace std;

template <class T>
class Rectangle {
        T width;
        T height;
    public:
        Rectangle(T w, T h){
            width = w;
            height = h;
        }

        void scale(T factor);
        T get_area(){
            return width * height;
        }

        void print(){
            cout << "Width: " << width << ", Height: " << height << endl;
        }
};

template <class T>
void Rectangle<T>::scale(T factor){
    width *= factor;
    height *= factor;
}

int main(){
    Rectangle<int> r1(1,2);
    r1.scale(2);
    r1.print();

    Rectangle<float> r2(1.1, 2.2);
    r2.scale(2.5);
    r2.print();

    return 0;
}
