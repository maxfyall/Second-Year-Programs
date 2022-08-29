#include <iostream>
using namespace std;

int max (int x, int y) {
  return (x > y) ? x : y;
}

int max(int x, int y, int z) {
    if (x > y){
        return (x > z) ? x : z;
    }else{
        return (y > z) ? y : z;
    }
}

int main() {
    cout << "Maximum of 2 and 4 is " << max(2,3) << endl;
    cout << "Maximum of 2, 3 and 4 is " << max(2,3,4) << endl;
}
