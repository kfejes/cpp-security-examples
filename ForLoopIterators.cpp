#include <iostream>
#include <vector>

using namespace std;

auto getVect() {
    vector<int> data;
    for (int i = 0; i < 10; ++i) {
        data.emplace_back(i);
    } 
    
    return data;
}

int main()
{
    for( auto itr = getVect().begin(); itr< getVect().end(); ++itr) {
        cout << *itr << endl;
    }

    return 0;
}