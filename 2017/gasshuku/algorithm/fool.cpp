#include <iostream>
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

int solve(int n) {
  auto cnt = 0;

  Timer timer;
  for (auto a = 0; a <= 1000; a++)
    for (auto b = 0; b <= 1000; b++)
      for (auto c = 0; c <= 1000; c++) {
	auto d = n - (a + b + c);
	if (d >= 0 && d < 1000) cnt++;
      }

  return cnt;
}
