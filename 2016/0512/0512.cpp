#include <bits/stdc++.h>
using namespace std;

struct Team{
  int id;
  int university;
  int solve;
  int penalty;

  Team(int i, int u, int s, int p) {
    id = i;
    university = u;
    solve = s;
    penalty = p;
  }
  bool operator < (const Team& o) const {
    if (solve != o.solve) return solve > o.solve;
    if (penalty != o.penalty) return penalty < o.penalty;
    return id < o.id;
  }
};

int main() {
  int n, i, u, a, p;
  while (cin >> n, n != 0) {
    vector<Team> v;
    for (int j = 0; j < n; j++) {
      cin >> i >> u >> a >> p;
      v.push_back(Team(i, u, a, p));
    }
    sort(v.begin(), v.end());
    
    int univ[n] = {}, cnt = 0;
    for (auto t : v) {
      int limit = cnt < 10 ? 3 : cnt < 20 ? 2 : cnt < 26 ? 1 : 0;
      if (univ[t.university] < limit) {
	cout << t.id << endl;
	univ[t.university]++;
	cnt++;
      }
    }
  } 
  return 0;
}
