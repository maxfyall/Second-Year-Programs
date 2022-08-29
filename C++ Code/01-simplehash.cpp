#include<iostream>
#include<vector>
using namespace std;

void printht(vector<int> &hashtable){
    cout << "The hashtable elements are: ";
    for (int i = 0; i < hashtable.size(); i++){
        cout << hashtable[i] << " ";
    }
    cout << endl;
}

int hash_function(int num, vector<int> &hashtable){
    return (num % hashtable.size());
}

bool insert(int num, vector<int> &hashtable){
    int index = hash_function(num, hashtable);
    int tryslot = index;
    while(hashtable[tryslot] != -1){
        // Linear probing with step size 1
        tryslot = (tryslot + 1) % hashtable.size();
        if (tryslot == index){
            return false;
        }
    }
    hashtable[tryslot] = num;
    return true;
}
        
        
int main() {
    int num = 0;
    vector <int> hashtable;
    hashtable.assign(11, -1);

    while (num != 999){
        cout << "Enter a number to insert (999 to quit): ";
        cin >> num;
        if(! insert(num, hashtable)){
            cerr << "TABLE FULL" << endl;
            return 1;
        }
        printht(hashtable);
    }

    return 0;
}
