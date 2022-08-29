#include <iostream>
using namespace std;

template <typename T> T 
getmin (T a, T b) {
    T result;
    result = (a<b)? a : b; return (result);
}

int main() {
    cout << getmin(1,2) << endl;
    cout << getmin(2.6, 3.7) << endl;
    return 0;
}
