#include <cstring>
#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

int n, k, is_visited[1011];
double fuel(pair<int, int> _point1, pair<int, int> _point2);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  pair<int, int> point[1011];
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> point[i].first >> point[i].second;
  }

  int l, h, m, minimum;
  l = 0;
  h = 20001;
  minimum = 20001;

  while (l + 1 < h) {
    memset(is_visited, 0, sizeof(is_visited));
    int reach = 0;

    m = (h + l) / 2;
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});

    while (!q.empty()) {
      int x = q.front().first.first;
      int y = q.front().first.second;
      int cnt = q.front().second;

      q.pop();
      if (cnt > k) {
        reach = 0;
        break;
      }
      if (fuel({10000, 10000}, {x, y}) <= m) {
        reach = 1;
        break;
      }

      for (int i = 0; i < n; i++) {
        if (is_visited[i])
          continue;
        int nx = point[i].first;
        int ny = point[i].second;

        if (fuel({nx, ny}, {x, y}) <= m) {
          q.push({{nx, ny}, cnt + 1});
          is_visited[i] = 1;
        }
      }
    }

    if (reach) {
      minimum = m;
      h = m;
    } else {
      l = m;
    }
  }
  cout << minimum;
}

double fuel(pair<int, int> _point1, pair<int, int> _point2) {
  int _x = _point1.first - _point2.first;
  int _y = _point1.second - _point2.second;
  int _x_distance = _x * _x;
  int _y_distance = _y * _y;

  double _fuel = sqrt(_x_distance + _y_distance) / 10;

  return _fuel;
}