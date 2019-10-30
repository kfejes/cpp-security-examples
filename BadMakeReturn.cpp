#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main() {

    auto msgPtr = make_unique<string>("testMessage");    
    auto movedMsgPtr = move(msgPtr); // OK
    auto found = movedMsgPtr->find("testMessage"); // OK
    msgPtr->find("testMessage"); // Segmentation fault

    return EXIT_SUCCESS;
}