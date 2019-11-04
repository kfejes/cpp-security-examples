#include <iostream>

using namespace std;

float sliceBy(int value) noexcept(true) {
    float cake = 1.0;

    if (value == 0) {
        throw "Division by zero";
    } else {
        return (cake / value);
    }
}

// int NoExceptFunction() noexcept(true) {
//     if (true) {
//         throw "Error, calling terminate()";
//     }

//     return 0;
// }

int main() {

    cout << "Example starting ... " << endl; 

    try{
        cout << sliceBy(4) << endl;
        cout << sliceBy(0) << endl;
    } catch ( ... ) {
        cout << " Exception catched" << endl;
    }

    return EXIT_SUCCESS;
}