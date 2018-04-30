#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> v;
  v.push_back(100);
  std::cout << "v size:" << v.size()<< '\n';
  std::cout << "v: " << v[0] << '\n';
  return 0;
}
