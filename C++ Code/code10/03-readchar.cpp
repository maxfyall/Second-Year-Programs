#include <string>
#include <fstream>
#include <iostream>
using namespace std ;

int main() {
  char letter;
  int i=0;

  ifstream reader( "file.txt" );

  if( ! reader ) {
    cout << "Error opening input file" << endl;
    return 1;
  }

  while(reader.get(letter)) {
    cout << letter;
    i++;
  }

  reader.close();
  cout << "Iterations: " << i << endl;
  
  return 0;
}

