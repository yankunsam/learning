#include <iostream>


int arr[] = {1,2,3};

int& setvalue(int i){
  return arr[i];
}

int main(int argc, char const *argv[]) {
  setvalue(1) = 12;
  std::cout << "value[1]: "<< arr[1] << '\n';
  return 0;
}
