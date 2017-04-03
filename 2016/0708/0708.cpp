#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class T, class Function, class E = typename T::value_type>
E search(const T& a, Function f) {
  E retval = E();
  for (const auto& e : a) {
    retval = f(retval, e);
  }
  return retval;
}

template<class T>
void getInput(vector<T>& v) {
  int n;
  cout << "Num data:";
  cin >> n;
  if(n == 0) v.push_back(T());
  else {
    v = vector<T>(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
  }
}

template<class T, class Function>
T func(T t, Function f) {
  vector<T> v;
  getInput(v);
  cout << search(v, f) << endl;
}

int getMode() {
  int mode;
  cout << "Select mode:";
  cin >> mode;
  return mode;
}

int main() {
  while (true) {
    switch (getMode()) {
    case 1: 
      func(int(), [](int a, int b) {return (a > b) ? a : b;});
      break;
    case 2:
      func(string(), [](string a, string b) {return (a > b) ? a : b;});
      break;
    case 3:
      func(string(),
	   [](string a, string b) {return (a.size() > b.size()) ? a : b;});
      break;
    default:
      return 0;
    }
  }
}
