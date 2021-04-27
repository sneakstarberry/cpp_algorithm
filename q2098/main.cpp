#include <algorithm>
#include <iostream>

using namespace std;
#define INF 987654321
int N, W[20][20], DP[20][1 << 20];

int dfs(int node, int visit) {
  if (visit == ((1 << N) - 1)) {
    return W[node][0];
  }
  if (DP[node][visit] != INF) {
    return DP[node][visit];
  }
  for (int i = 0; i < N; i++) {
    if ((visit & (1 << i)) == 0 && (W[node][i] != 0)) {
      DP[node][visit] =
          min(DP[node][visit], dfs(i, (visit | (1 << i))) + W[node][i]);
    }
  }

  return DP[node][visit];
}

int main() {
  cin >> N;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      W[i][j] = INF;
    }
    for (int j = 0; j < (1 << 20); j++) {
      DP[i][j] = INF;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int tmp;
      cin >> tmp;
      if (tmp != 0) {
        W[i][j] = tmp;
      }
    }
  }

  cout << dfs(0, 1);
  return 0;
}