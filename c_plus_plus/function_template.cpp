#include <iostream>
#include <string>

template <typename T>
inline T const& Max(T const& a, T const& b){
  return a < b? b:a;
}
int main(int argc, char const *argv[]) {
  int i = 1;
  int j = 2;
  std::cout << "Max: " << Max(i,j) << '\n';
  return 0;
}
