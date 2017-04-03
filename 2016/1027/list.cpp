#include <iostream>
#include <list>

int main() {
  std::list<int> lst;
  lst.push_back(1);
  lst.push_front(2);
  std::cout << lst.size() << std::endl;
  lst.pop_back();
  std::cout << lst.size() << std::endl;

  return 0;
}
