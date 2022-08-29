#include <iostream>
using namespace std;

template <typename T, typename U>
T getmin (T a, U b) {
    return ((a<b) ? a : b);
}

int main() {
    cout << getmin(1.1, 2) << endl;
    cout << getmin<float, float>(2.6, 3.7) << endl;
    cout << getmin<int, float>(2, 3.7) << endl;
    return 0;
}
