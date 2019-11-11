#include <iostream>
#include <cmath>

using namespace  std;

bool IsGreaterThan(float value) {

    if (value >= 10.0) {
        cout << "Branch True" << endl;
        return true;        
    } else if (value < 10.0) {
        cout << "Branch False" << endl;
        return false;        
    } else {
        cout << "What Else?" << endl; // is there any valid return value?
    } 
}

int main() {

    float value = NAN;
  
    auto retVal = IsGreaterThan(4.2);
    auto retVal1 = IsGreaterThan(14.2);
    auto retValNan = IsGreaterThan(value);

    cout << retValNan << endl;

    return 0;
}