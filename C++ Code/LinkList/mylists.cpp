#include "LinkedList.h"
#include <iostream>
using namespace std;

int main(){
    Linklist<int> mylist;
    for(int i=1; i<=10; i++){
        mylist.ins(i);
    }
    cout << mylist << endl;

    for(int i=0; i<=10; i+=3){
        if(! mylist.del(i)){
            cout << "Cannot delete " << i << endl;
        }
    }
    cout << mylist << endl;

    Linklist<string> mylist2;
    mylist2.ins("here");
    mylist2.ins("is");
    mylist2.ins("string");
    cout << mylist2 << endl;

    return 0;
}
