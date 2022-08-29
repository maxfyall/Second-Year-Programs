#include <string>
#include <sstream>
#include <iostream>
using namespace std ;

int main( )
{
  string term = "100"; 
  int num; 
  stringstream stream; 

  stream << term; 
  stream >> num; 
  num /= 4; 
  cout << "Integer value: " << num << endl;

  // Reset the stream object back to new...
  stream.clear();
  stream.str("");

  int number = 56;
  string text;
  
  stream << number; 
  stream >> text; 
  text += " Per Cent";
  cout << "String value: " << text << endl;

  return 0 ;
}
