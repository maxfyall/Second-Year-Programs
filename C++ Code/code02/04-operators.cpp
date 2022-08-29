#include<iostream>
using namespace std;

int main() {
    int i = 10, j = 0;
    cout << "i:" << i << " j:" << j << endl;
    i %= 3;
    cout << "i:" << i << " j:" << j << endl;
    j = i++;
    cout << "i:" << i << " j:" << j << endl;
    j = ++i;
    cout << "i:" << i << " j:" << j << endl;
    int k = j > i ? 10 : 20;
    cout << "i:" << i << " j:" << j << " k:" << k << endl;
    return 0;
}
