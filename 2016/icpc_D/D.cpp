#include <bits/stdc++.h>
using namespace std;

void Disp(int n, const vector<vector<int> >& dp) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }
}
int solve(int n, vector<int>& w) {
  vector<vector<int> >dp(n, vector<int>(n,0));
  for (int i = 1; i < n; i++) {
    for (int L = 0; L < n - i; L++) {
      int R = L+i;
      if (i % 2 == 0) {
	dp[L][R] = max(dp[L][R-1], dp[L+1][R]);
      }
      else {
	int n1 = dp[L+1][R-1];
	if (n1 == i -1 && abs(w[L] - w[R]) < 2) {
	  n1 += 2;
	}
	int n2 = dp[L][L + i / 2] + dp[L + i / 2 + 1][R];
	dp[L][R] = max(n1,n2);
      }
    }
    Disp(n, dp); //
    cout << endl; //
  }

  return dp[0][n-1];
}

int main() {
  int n;
  while(cin >> n, n != 0) {
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    cout << solve(n, w) << endl;
  }
}
