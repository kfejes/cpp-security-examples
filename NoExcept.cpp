#include <iostream>
#include <vector>
#include <random>

using namespace std;

random_device dev;

class DataHolder {
    private:
        vector<int> data;
        auto generateRandom(int from, int to) {    
            mt19937 rng(dev());
            uniform_int_distribution<mt19937::result_type> dist6(from, to); 

            return dist6(rng);
        }

        void fillUp(int count) {
            this->data.reserve(count);

            for (int i = 0; i < count; ++i) {
                data.emplace_back(generateRandom(1, 100));
            }
        }

    public:
        DataHolder(int countOfData) {
            fillUp(countOfData);
        }
        ~DataHolder() = default;

        auto getValue(int place) noexcept {
            return this->data.at(place);
        }
};

int main() {

    DataHolder dh(100);

    cout << dh.getValue(42) << endl;
    cout << dh.getValue(666) << endl; // out of boundary, this will throw and exception

    return EXIT_SUCCESS;
}