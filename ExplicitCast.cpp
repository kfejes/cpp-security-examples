#include <iostream>

using namespace std;

class Complex {
    double re, im;
    public:
        Complex(double r, double i) : re(r), im(i) { }
        Complex(double r) : Complex(r, 0) { }
        operator double() const {
            return re;            
        }
};

void callComplex(Complex c) {
    cout << static_cast<double>(c) << endl;
}

void callReal(double r) {
   cout << r << endl;
}

int main() {
    Complex num(9, 7);    
    
    callComplex(3);    
    callReal(num);

}