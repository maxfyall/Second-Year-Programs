#include <iostream>
#include <string>
using namespace std;

template <typename T>
void printsum(T a, T b)
{
    T c = a + b;
    cout << a << " + " << b << " = " << c << endl;
}

int main() {
    printsum(1,2);
    printsum(2.6, 3.7);
    printsum<string>("Hello", " world");

    return 0;
}
