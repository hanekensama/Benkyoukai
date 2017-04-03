#include <iostream>
#include "Timer.hpp"
using namespace std;

int combination[2001]; // 0 ~ 2000

inline void init();
inline int solve(int n);

int main() {
  int n;
  init();
  while (cin >> n) {
    Timer timer;
    auto answer = solve(n);
    auto time = timer.elapsed();

    cout << answer << endl;
    cout << time << "micro sec" << endl;
  }
  return 0;
}

inline void init() {
  for (auto i = 0; i <= 1000; i++)
    for (auto j = 0; j <= 1000; j++)
      combination[i+j]++;
}

inline int solve(int n) {
  auto cnt = 0;
  auto last = std::min(n, 2000);
  
  for (auto ab = 0; ab <= last; ab++) {
    auto cd = n - ab;
    if (cd <= 2000)
      cnt += combination[ab] * combination[cd];
  }

  return cnt;
}

