#include <iostream>
using namespace std;

// Using a recursive function to calculate factorials
int factorial(int n);

int main() {
   int number=0, result;

   cout << "Integer number: ";
   cin >> number;

   result = factorial(number);

   cout << "Factorial = " << result << endl;
   return 0;
}

int factorial(int n) {
    if(n == 1){
        return 1;
    }else{
        return n * factorial(n-1);
    }
}
