#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const char* securePass = "goodpassword";

auto getPass() {
    string pass;
    cout << "Enter password: ";
    cin >> pass;
    return pass.c_str();
}

auto getSecuredData() {
    string secureData = "Meaning Of Life";
    auto pwd = getPass();

    if (strcmp(pwd, securePass) == 0) {
        memset(&pwd, 0, strlen(pwd));
        return secureData;
    } else {
        const string error = "Incorrect parameter";
        memset(&pwd, 0, strlen(pwd));
        return error;
    }
}

int main() {
    cout << getSecuredData() << endl;

    return EXIT_FAILURE;
}