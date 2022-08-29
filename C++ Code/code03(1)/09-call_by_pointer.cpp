#include<iostream> 
using namespace std; 
void increment(int *x){
    (*x)++; 
} 
int main(){ 
    int x = 1; 
    cout << "x: " << x << endl; 
    increment(&x); 
    cout << "x: " << x << endl; 
    return 0;
}

