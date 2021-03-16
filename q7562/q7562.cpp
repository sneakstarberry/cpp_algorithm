#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int N, L, MAX, IS_VISITED[301][301];
pair<int, int> S, E;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void dfs(int x, int y, int cnt);
void bfs();

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> L;

    for (int i = 0; i < L; i++) {
      memset(IS_VISITED[i], 0, sizeof(IS_VISITED[i]));
    }
    cin >> S.first >> S.second;
    cin >> E.first >> E.second;
    MAX = 0;

    if (S.first == E.first && S.second == E.second) {
      cout << 0 << endl;
      continue;
    }

    dfs(S.second, S.first, 0);
    // bfs();
  }
}

void dfs(int x, int y, int cnt) {

  if (E.second == x && E.first == y) {
    cout << cnt << endl;
    return;
  }

  for (int i = 0; i < 8; i++) {
    int n_x = x + dx[i];
    int n_y = y + dy[i];

    if (0 <= n_x && n_x < L && 0 <= n_y && n_y < L && !IS_VISITED[n_y][n_x]) {
      IS_VISITED[n_y][n_x] = 1;
      dfs(n_x, n_y, cnt + 1);
    }
  }
}

void bfs() {
  queue<pair<int, pair<int, int>>> q;
  for (int i = 0; i < L; i++) {
    memset(IS_VISITED[i], 0, sizeof(IS_VISITED[i]));
  }

  q.push({0, {S.first, S.second}});
  IS_VISITED[S.first][S.second] = 1;

  while (!q.empty()) {
    int x = q.front().second.second;
    int y = q.front().second.first;
    int cnt = q.front().first;

    q.pop();

    if (E.second == x && E.first == y) {
      cout << cnt << endl;
      break;
    }

    for (int i = 0; i < 8; i++) {
      int n_x = x + dx[i];
      int n_y = y + dy[i];

      if (0 <= n_x && n_x < L && 0 <= n_y && n_y < L && !IS_VISITED[n_y][n_x]) {
        IS_VISITED[n_y][n_x] = 1;
        q.push({cnt + 1, {n_y, n_x}});
      }
    }
  }
}