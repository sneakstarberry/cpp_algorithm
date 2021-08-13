#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'
#define INF 21

using namespace std;

int N;
vector<int> MAP[INF];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, T = 0, E = 0, S = 2;

struct FEED {
  int dist;
  int y;
  int x;
  bool operator<(const FEED &b) const {
    if (dist == b.dist) {
      if (y == b.y) {
        return x > b.x;
      } else {
        return y > b.y;
      }
    } else {
      return dist > b.dist;
    }
  }
};

FEED bfs(FEED start) {
  queue<FEED> q;
  priority_queue<FEED> feeds;
  bool is_visited[INF][INF] = {
      false,
  };

  MAP[start.y] [start.x] = 0;

  is_visited[start.y][start.x] = true;
  q.push({0, start.y, start.x});

  while (!q.empty()) {
    int dist = q.front().dist;
    int y = q.front().y;
    int x = q.front().x;

    q.pop();

    for (int i = 0; i < 4; i++) {
      int nxt_y = y + dy[i];
      int nxt_x = x + dx[i];

      if (!(0 <= nxt_y && nxt_y < N && 0 <= nxt_x && nxt_x < N))
        continue;
      if (is_visited[nxt_y][nxt_x] || MAP[nxt_y][nxt_x] > S)
        continue;
      is_visited[nxt_y][nxt_x] = true;
      q.push({dist + 1, nxt_y, nxt_x});
      if (MAP[nxt_y][nxt_x] < S && MAP[nxt_y][nxt_x] != 0) {
        feeds.push({dist + 1, nxt_y, nxt_x});
      }
    }
  }

  if (feeds.empty()) {
    return {-1, -1, -1};
  }

  FEED feed = feeds.top();

  if (++E == S) {
    E = 0;
    S++;
  }

  T += feed.dist;
  return {0, feed.y, feed.x};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  FEED start;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int tmp;
      cin >> tmp;

      if (tmp == 9) {
        start = {0, i, j};
      }

      MAP[i].push_back(tmp);
    }
  }

  while (1) {
    start = bfs(start);

    if (start.dist == -1 && start.y == -1 && start.x == -1) {
      cout << T;
      break;
    }
  }

  return 0;
}