#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  std::cout << v.size() << std::endl;
  v.pop_back();
  std::cout << v.size() << std::endl;
  return 0;
}
