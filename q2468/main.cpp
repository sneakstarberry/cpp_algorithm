#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAX 101

using namespace std;

int N;
int v[MAX][MAX];
bool is_visited[MAX][MAX];
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};
int CNT = 0;
int END = 0;
int H;

void bfs(int col, int row) {
  queue<pair<int, int>> q;
  is_visited[col][row] = true;
  q.push(make_pair(col, row));
  CNT++;

  while (!q.empty()) {
    int cur_c = q.front().first;
    int cur_r = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int cur_y = cur_c + y[i];
      int cur_x = cur_r + x[i];

      if (0 <= cur_y && N > cur_y && 0 <= cur_x && N > cur_x) {
        if (is_visited[cur_y][cur_x] || v[cur_y][cur_x] < H) {
          continue;
        }

        is_visited[cur_y][cur_x] = true;
        q.push(make_pair(cur_y, cur_x));
      }
    }
  }
  return;
}
int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> v[i][j];
    }
  }
  for (int k = 1; k <= 100; k++) {
    H = k;
    CNT = 0;
    memset(is_visited, 0, sizeof(is_visited));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (is_visited[i][j] || v[i][j] < k) {
          continue;
        }
        bfs(i, j);
      }
    }
    if (END < CNT) {
      END = CNT;
    }
  }

  cout << END;

  return 0;
}
