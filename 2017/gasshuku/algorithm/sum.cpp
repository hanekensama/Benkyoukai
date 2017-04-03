#include <iostream>
#include <string>
#include "Timer.hpp"
using namespace std;

inline int solve(int n);

int main() {
  int n;
  while (cin >> n) {
    Timer timer;
    auto answer = solve(n);
    auto time = timer.elapsed();

    cout << answer << endl;
    cout << time << "micro sec" << endl;
  }

  return 0;
}

inline int solve(int n) {
  return 0;
}
