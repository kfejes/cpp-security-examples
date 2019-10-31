#include <iostream>
#include <exception>

using namespace std;

void leak(int x)   // don't: may leak
{
    auto p = new int{7};
    if (x < 0) throw "Err";  // may leak *p    
    delete p;   // we may never get here
}


int main() {
    try {
        leak(-4);
    } catch ( ... ) {
        cout << "Memory is leaking..." << endl;
    }
    
    return 0;
}