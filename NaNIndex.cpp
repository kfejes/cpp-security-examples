#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


double floatRandom(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

auto NanIndex() {
    vector<double> data;

    float index = NAN;

    for (int i = 0; i < 10; ++i) {
        double random_variable = floatRandom(0.0, 100.0);
        data.emplace_back(random_variable);
    }

    cout << data[int(index)] << endl;

    return data;
}

int main() {

    auto data = NanIndex();

    return EXIT_SUCCESS;
}