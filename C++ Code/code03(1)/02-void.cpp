#include<iostream>
using namespace std;
void divide(int x, int y){
    if(y == 0){
        cout << "Division by zero" << endl;
        return;
    }
    cout << x << "/" << y << "=" << (x/y) << endl;
}

int main(){
    divide(10,5);
    divide(10,0);
    return 0;
}
