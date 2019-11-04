#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    vector<int> data;

    data.reserve(10);
    for (int i = 0; i < 10; ++i) {
        data.emplace_back(i);
    } 

    for (auto value : data) {
        if ((value % 3) == false) {
            data.emplace_back(42);
            cout << value << "*" << endl;
        } else {
            cout << value << endl;
        }
    } 

    return EXIT_SUCCESS;
}