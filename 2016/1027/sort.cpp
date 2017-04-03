#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<int> v;
  while(true) {
    int i;
    cin >> i;
    if (i == 0) break;
    v.push_back(i);
  }
  sort(v.begin(), v.end());
  for(auto i : v) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
