#include <iostream>

using namespace std;

int N, cities[11][11], ANS = (1 << 31) - 1;
bool is_visited[11] = {
    false,
};

void dfs(int cur, int dist, int cnt, int start) {
  if (dist > ANS)
    return;
  if (cnt == N && start == cur) {
    if (dist < ANS) {
      ANS = dist;
    }
    return;
  }

  for (int i = 0; i < N; i++) {
    if (is_visited[i])
      continue;
    if (!cities[cur][i])
      continue;

    is_visited[i] = true;
    dfs(i, dist + cities[cur][i], cnt + 1, start);
    is_visited[i] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> cities[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    dfs(i, 0, 0, i);
  }

  cout << ANS;

  return 0;
}