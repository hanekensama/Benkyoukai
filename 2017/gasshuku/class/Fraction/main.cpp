#include <iostream>
#include <vector>
#include <algorithm>
#include "Fraction.hpp"

using namespace std;

void demo();

int main() {
  vector<Fraction> v;
  int a, b;

  demo();
  
  while (cin >> a >> b, a != 0) {
    v.push_back(Fraction(a, b));
  }

  cout << "Before Sort" << endl;
  for (auto f : v) cout << f << " ";
  cout << endl;

  sort(v.begin(), v.end());
  
  cout << "After Sort" << endl;
  for (auto f : v) cout << f << " ";
  cout << endl;
}

void demo() {
  Fraction a(2, 3), b(3, 5);
  cout << a << "+" << b << "=" << a+b << endl;
  cout << a << "-" << b << "=" << a-b << endl;
  cout << a << "*" << b << "=" << a*b << endl;
  cout << a << "/" << b << "=" << a/b << endl;
  cout << "value of " << a << "is" << (double)a << endl;
  cout << "value of " << b << "is" << (double)b << endl;
}
