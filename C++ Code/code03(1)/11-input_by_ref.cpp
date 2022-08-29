#include <iostream>
using namespace std;

// Another function for getting user input (call by reference)
// Shows how simple error checking can be added in just one
// place by using a function for input.

void inputint(int &n){
    cout << "Enter a number: ";
    cin >> n;
    if(n < 0){
        cout << "ERROR: Please enter a number greater than zero" << endl;
        inputint(n);
    }
}

int main(){
    int n1, n2, n3;

    inputint(n1);
    inputint(n2);
    inputint(n3);

    if((n1 >= n2) && (n1 >= n3))
        cout << "Largest number: " << n1 << endl;
    else if ((n2 >= n1) && (n2 >= n3))
        cout << "Largest number: " << n2 << endl;
    else
        cout << "Largest number: " << n3 << endl;

    return 0;
}
