#include<iostream>
#include<string>
using namespace std;

//bool even(int n);
//bool odd(int n);

bool even(int n) {
    if(n == 0){
        return true;
    }else{
        return odd(n-1);
    }
}

bool odd(int n){
    if(n == 0){
        return false;
    }else{
        return even(n-1);
    }
}

int main(){
    int n;
    string odd_even;
    cout << "Enter a number: ";
    cin >> n;
    odd_even = even(n) ? "Even" : "Odd";
    cout << n << " is " << odd_even << endl;
    return 0;
}
