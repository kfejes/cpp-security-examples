#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> data;
    auto Limit = 1024 * 1024 * 1024 * 5; // integer overflow, warningot ad a compiler

    for (auto i = 0; i < Limit; ++i) {
        data.emplace_back(i);
    }

    return EXIT_SUCCESS;

}