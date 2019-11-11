#include <optional>
#include <iostream>

#if defined(__has_feature)
#  if __has_feature(memory_sanitizer)
// code that builds only under MemorySanitizer
    #pragma message("code that builds only under MemorySanitizer") 
#  endif
#endif

using namespace std;

int returnOptional() {
    optional<int> x(nullopt);
    return *x;
}

int main() {

    auto value = returnOptional();
    cout << value << endl;

    return EXIT_SUCCESS;
}

/* 
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=leak-out.txt ./OptionalUB.app
*/ 