#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

auto CopyVectorBad() {

    vector<int>src;
    vector<int>dest; // memory allocation missing, fix is dest.reserve(100)

    for (int i = 0; i < 100; ++i) {
        src.emplace_back(i);
    }
    copy(src.begin(), src.end(), dest.begin()); // segmentation fault

    return dest;
}

int main() {

    auto data = CopyVectorBad();

    return EXIT_SUCCESS;
}

