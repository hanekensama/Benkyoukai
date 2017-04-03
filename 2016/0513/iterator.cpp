#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{10, 15, 100, 13, 1, 5};
  std::vector<int>::iterator itr;
  itr = v.begin();
  std::cout << *itr << std::endl;
  itr++;
  std::cout << *itr << std::endl;
  itr = v.end();
  std::cout << *itr << std::endl;
  itr--;
  std::cout << *itr << std::endl;

  for(itr = v.begin(); itr != v.end(); itr++) {
    std::cout << *itr << " ";
  }
  std::cout << std::endl;
}
