#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector <int> v;
    // set vector to contain 5 elements with value 0
    v.assign(5, 0);
    v.push_back(1);

    cout << "The vector elements are: ";
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
