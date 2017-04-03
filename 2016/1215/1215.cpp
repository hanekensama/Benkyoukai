#include <iostream>
#include <vector>

const auto MEMO_SIZE = 100000000;
long long memo[MEMO_SIZE];

auto init_memo() -> void;
auto memoization(long long i, long p, long q, long x, long y)
  -> long long;
auto DP(long long i, long p, long q, long x, long y)
  -> long long;

auto main() -> int {
  long long n;
  long p, q, x, y;
  while(true) {
    std::cin >> n >> p >> q >> x >> y;
    if ((n | p | q | x | y) == 0) return 0;

    init_memo();
    auto memo_result = memoization(n, p, q, x, y);
    std::cout << "memoization: " << memo_result << std::endl;
    auto dp_result = DP(n, p, q, x, y);
    std::cout << "DP         : " << dp_result << std::endl;
  }
}

auto init_memo() -> void {
  for (long long i = 0; i < MEMO_SIZE; i++) {
    memo[i] = -1;
  }
}

auto memoization(long long i, long p, long q, long x, long y)
  -> long long {
  if (i <= 0) return 1;

  if (memo[i] == -1) {
    memo[i] = memoization((i / p - x), p, q, x, y) +
              memoization((i / q - y), p, q, x, y);
  }
  
  return memo[i];
}

auto DP(long long i, long p, long q, long x, long y)
  -> long long {
  std::vector<long long> dp(MEMO_SIZE, 0);
  auto value = [&dp](long long i) { return (i < 0) ? 1 : dp[i]; };
  dp[0] = 1;
  
  for (int j = 1; j <= i; j++) {
    dp[j] = value(j / p - x) + value(j / q - y);
  }

  return dp[i]; 
}
