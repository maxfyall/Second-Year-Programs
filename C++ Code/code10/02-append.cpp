#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main() {
  string info = "This is appended to the file.";

  ofstream writer( "file.txt" , ios::app );

  if( ! writer ) {
    cerr << "Error opening file for output" << endl;
    return 1;
  }
  
  writer << info << endl;
  writer.close();

  return 0;
}
