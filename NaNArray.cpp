#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

double floatRandom(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

void NanTest() {
    vector<double> data;
    std::srand(std::time(nullptr));

    for (int i = 0; i < 10; ++i) {
        double random_variable = floatRandom(0.0, 100.0);
        data.emplace_back(random_variable);
    }
    data[4] = NAN;
    sort(data.begin(), data.end());
    
    int index = 0;

    for (auto &i : data) {
        index++;
        cout << index << ": " << i << endl;
    }
}

int main() {
    NanTest();
    return EXIT_SUCCESS;
}