#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>


#define endl '\n'

using namespace std;

int N, M, area = 0;
bool visited[51][51] = {
    false,
};

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int map[51][51];

int bfs(int y, int x) {
  queue<pair<int, int>> q;

  q.push({y, x});
  visited[y][x] = true;
  int cnt = 1;

  while (!q.empty()) {
    int cur_y = q.front().first;
    int cur_x = q.front().second;

    q.pop();
    int bit = 1;
    for (int i = 0; i < 4; i++) {
      if (!(map[cur_y][cur_x] & bit)) {
        int nxt_y = cur_y + dy[i];
        int nxt_x = cur_x + dx[i];

        if (0 > nxt_x || N <= nxt_x || 0 > nxt_y || M <= nxt_y)
          continue;
        if (!visited[nxt_y][nxt_x]) {
          cnt++;
          visited[nxt_y][nxt_x] = true;
          q.push({nxt_y, nxt_x});
        }
      }
      bit <<= 1;
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
    }
  }

  int cnt = 0;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j]) {
        area = max(area, bfs(i, j));
        cnt++;
      }
    }
  }

  cout << cnt << endl;
  cout << area << endl;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 1; k <= 8; k <<= 1) {
        if (map[i][j] & k) {
          memset(visited, false, sizeof(visited));
          map[i][j] -= k;
          area = max(area, bfs(i, j));
          map[i][j] += k;
        }
      }
    }
  }

  cout << area << endl;

  return 0;
}