#include <iostream>
using namespace std;

namespace other {
  int x = 24;
}

int main() {
  int x = 48;
  cout << "other::x = " << other::x << endl;
  cout << "x = " << x << endl; 
}
