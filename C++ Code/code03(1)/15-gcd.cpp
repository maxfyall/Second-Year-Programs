#include <iostream>
using namespace std;

/*
gcd(x,y) = x                         if y=0
         = gcd(y, remainder(x,y))    if y>0
*/

int gcd(int x, int y);

int main() {
   int num=0, den=0;

   cout << "Numerator: ";
   cin >> num;
   cout << "Denominator: ";
   cin >> den;

   int gcd_num_den = gcd(num, den);

   if (gcd_num_den == 1){
      cout << num << "/" << den << " cannot be simplified" << endl;
   }else{
      cout << num << "/" << den << " can be simplified to " << 
        (num/gcd_num_den) << "/" << (den/gcd_num_den) <<endl;
   }
   return 0;
}

int gcd(int x, int y) {
    if(y == 0){
        return x;
    }else{
        return gcd(y, x%y);
    }
}
