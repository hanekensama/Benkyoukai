#include <iostream>
#include <string>
#include "hub_list.hpp"

using namespace std;
using namespace hub;

int main() {
  auto l1 = List<string>();
  l1.pushBack("hoge");
  l1.pushBack("fuga");
  l1.pushFront("piyo");

  l1.disp();

  auto l2 = l1;
  l2 = l1;
  auto l3 = move(l1);
  l3 = move(l2);
  
}
