#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


auto remove(map<string, int> data, string user) {
    for (auto i : data) {

        if (i.first == user) {
            data.erase(i.first);
        }
        cout << i.first << endl;
    }
    return data;
}

void check(map<string, int> data) {
    for (auto i : data) {
        cout << i.first << endl;
    }
}

int main() {

    map<string, int> dataHolder;

    for (int i = 0; i < 10; ++i) {
        string user = "User:" + to_string(i);
        dataHolder.insert({user, i});
    }
    
    dataHolder = remove(dataHolder, "User:5");
    dataHolder = remove(dataHolder, "User:6");
    check(dataHolder);


}

