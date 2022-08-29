#include <string>
#include <iostream>

using namespace std;

int main() {

  string name;

  cout << "Please enter your full name: ";
  cin >> name;

  cout << "Welcome " << name << endl;

  cout << "Please re-enter your full name: ";

  //  cin.ignore( 256, '\n' ); // uncomment to fix the problem
  getline( cin, name );

  cout << "Thanks, " << name << endl;

  return 0; 

}

