#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

int main() {    

    vector<int> data;
    auto Limit = 1024 * 1024 * 1024 * 5; // integer overflow, warningot ad a compiler

    for (short int i = 0; i < Limit; ++i) {
        cout << i << endl;
        data.emplace_back(i);
    }

    return EXIT_SUCCESS;

}