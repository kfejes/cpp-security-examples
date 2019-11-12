#include <iostream>
#include <string>
#include <string_view>
#include <chrono>
#include <vector>

using namespace std;

auto createData(const int count) {
    vector<string> data;
    data.reserve(count);

    for (int i = 0; i < count; ++i) {
        string msg = "Message #" + to_string(i);
        data.emplace_back(msg);
    } 

    return data;
}

auto convertToView(string input) { // ok, every string exists
    string_view view(input); 
    return view;
}

auto createUserNameFromID(const int id) { // misusing string_view
    string username = "user" + to_string(id); 
    return string_view(username); // username string is not exists anymore
}

auto createUserNameFromIDGood(const int id) {
    string username = "user" + to_string(id);
    return username;
}

int main() {

    auto data = createData(3);
    auto view = convertToView(data[0]);
    auto view1 = convertToView(data[1]);

    cout << view << endl;
    cout << view1 << endl;

    auto val = createUserNameFromID(1);
    cout << val << endl;

    auto user1 = createUserNameFromIDGood(1);
    auto user2 = createUserNameFromIDGood(2);

    cout << user1 << " " << user2 << endl;

    return EXIT_SUCCESS;
}