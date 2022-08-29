#include <iostream>
using namespace std;

#define PI 3.14159265

int main() {
   const float radius = 0.5;  
   float area;

   area = PI * radius * radius;
   
   cout << "A circle with radius " << radius <<
        " has area " << area << endl;
   return 0;
}
