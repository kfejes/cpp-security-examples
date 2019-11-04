#include <iostream>

#include <string>
#include <experimental/string_view>

using namespace std;
using namespace experimental;

int main() {
  string s = "Hellooooooooooooooo ";
  string_view sv = s + "World\n";
  cout << sv;
}
