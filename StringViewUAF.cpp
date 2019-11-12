#include <iostream>

#include <string>
#include <string_view>

using namespace std;

int main() {
  string s = "Hellooooooooooooooo ";
  string_view sv = s + "World\n";
  cout << sv;
}
