#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  //g++ -std=c++11 vector.cpp
  vector<int> v = {1,2,3,4,5};
  for(auto i : v)
      std::cout << "v: " <<  i<< '\n';
  std::cout << "v size:" << v.size()<< '\n';
  std::cout << "v: " << v[0] << '\n';
  return 0;
}
