#include <iostream>

int main(int argc, char const *argv[]) {
  int i = 0;
  int& j = i;
  std::cout << "i: " << i << '\n';
  std::cout << "j: " << j << '\n';
  j = j + 1;
  std::cout << "[after: j + 1] i: "<< i << '\n';
  std::cout << "[after: j + 1] j: " << j << '\n';
  return 0;
}
