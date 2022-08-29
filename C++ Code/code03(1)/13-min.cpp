#include <iostream>
using namespace std;

char min(char a, char b) {
  return (a < b) ? a : b;
}

int min(int a, int b) {
  return (a < b) ? a : b;
}

double min(double a, double b) {
  return (a < b) ? a : b;
}

int main() {
  cout << "Minimum of 2 and 3 is " << min(2,3) << endl;
  cout << "Minimum of X and A is " << min('X','A') << endl;
  cout << "Minimum of -5.98 and 2.34 is " << min(-5.98,2.34) << endl;
}
