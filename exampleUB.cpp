#include <iostream>

using namespace std;

auto isThatMeaningOfLife(int value) {
    int result;
    if (value == 42) {
        result = value;
    }  
    
    return result;
}

int main() {

    cout << isThatMeaningOfLife(42) << endl;
    cout << isThatMeaningOfLife(32) << endl;

    return 0;
}