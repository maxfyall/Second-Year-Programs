#include<iostream>
#include "06-header.h"
using namespace std;

int main(){
    cout << "3+4="<< add(3,4) << endl;
    return 0;
}

int add(int x, int y){
    return (x+y);
}
