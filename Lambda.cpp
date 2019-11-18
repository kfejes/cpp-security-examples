#include <iostream>
#include <string>

using namespace std;

auto getMessage() {
    static int x = 0;
    string msg = "Message #";
    auto inc = [&]() {                
        x++;
        return msg + to_string(x);;
    };
    return inc;
}

int main() {
    auto getMsg = getMessage();

    cout << getMsg() << endl;
    cout << getMsg() << endl;
    cout << getMsg() << endl;
    cout << getMsg() << endl;

    return EXIT_SUCCESS;
}