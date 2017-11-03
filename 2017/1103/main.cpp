#include <iostream>
#include "three_d.hpp"
using namespace std;

auto main() -> int {
  three_d o1(10, 10, 10), o2(2, 3, 4), o3;

  o3 = o1 + o2;
  //cout << o3 << endl;
  int x, y, z;
  o3.get(x, y, z);
  cout << "(" << x << ", " << y << ", " << z << ")" << endl;

  o3 = o1 - o2;
  cout << o3 << endl;

  ++o1;
  cout << o1 << endl;

  o1++;
  cout << o1 << endl;

  --o1;
  cout << o1 << endl;

  o1--;
  cout << o1 << endl;
  
  return 0;
}
