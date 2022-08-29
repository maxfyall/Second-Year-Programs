#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main() {
  string info = "ABC";

  ofstream writer( "file.txt" );

  if( ! writer ) {
    cerr << "Error opening file for output" << endl;
    return 1;
  }

  writer << info << endl << 123 << endl;
  writer.close();

  return 0;
}
