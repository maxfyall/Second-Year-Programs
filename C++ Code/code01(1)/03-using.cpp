#include <iostream> 
using namespace std; 
namespace other { int x = 24; } 
namespace mine { int y = 48; } 
using namespace other; 
using namespace mine;
 
int main() { 
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

