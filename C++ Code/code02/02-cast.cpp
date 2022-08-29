#include <iostream>
using namespace std;
 
int main() {
   double a = 21.09399;
   int b = 0;
   int c = 100;
   float d = 0.0;
 
   b = (int) a;
   cout << "a=" << a << "   (int)a=" << b << endl;
   
   d = (float) c;
   cout << "c=" << c << "   c/3=" << c/3 << endl;
   cout << "c=" << c << "   (float)c/3=" << d/3 << endl;
   
   return 0;
}
