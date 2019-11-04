#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> AList;
    vector<int> BList;

    auto iterA = AList.begin();
    auto iterB = BList.begin();

    if (iterA == iterB) {
        cout << "equal" << endl;
    } else {
        cout << "not equal" << endl;
    }

    return EXIT_SUCCESS;
}

