#include <iostream>

[[noreturn]] int foo() {
    return 42;
}

int main() {
    foo();
    return EXIT_SUCCESS;
}