#include <string>
#include <iostream>
using namespace std;

int main()
{
  string nums = "0123456789012345678901234567890123";
  string text = "I do like the seaside";

  cout << endl;
  cout << "                    " << nums << endl;
  cout << "text              = " << text << endl;

  text.insert(10, "to be beside " );
  cout << "insert(10, ...)   = " << text << endl ;

  text.erase( 2, 3 );
  cout << "erase( 2, 3)      = " << text << endl;

  text.replace( 7, 25, "strolling by the sea" );
  cout << "replace(7,25,...) = " << text << endl;
  cout << "substr( 7, 9)     = " << text.substr( 7, 9 ) << endl;
  cout << "Last character: " << text.at( text.size() - 1 ) << endl;

  return 0;
}
