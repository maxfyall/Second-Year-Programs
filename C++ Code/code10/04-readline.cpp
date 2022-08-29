#include <string>
#include <fstream>
#include <iostream>
using namespace std ;

int main() {
  string line;
  int i=0;

  ifstream reader( "file.txt" );

  if( ! reader ) {
    cout << "Error opening input file" << endl;
    return 1;
  }

  while(getline(reader, line)) {
    cout << line << endl;
    i++;
  }

  reader.close();
  cout << "Iterations: " << i << endl;
  
  return 0;
}
