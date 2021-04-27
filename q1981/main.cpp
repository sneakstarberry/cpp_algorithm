#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, CHART[101][101], IS_VISITED[101][101];
int MIN = 201;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
vector<int> VEC;

int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> CHART[i][j];
      VEC.push_back(CHART[i][j]);
    }
  }

  int low = 0, high = 0, result = 987654321;
  sort(VEC.begin(), VEC.end());
  VEC.erase(unique(VEC.begin(), VEC.end()), VEC.end());

  while (low < VEC.size()) {
    memset(IS_VISITED, 0, sizeof(IS_VISITED));
    queue<pair<int, int>> q;

    if (CHART[0][0] >= VEC[low] && CHART[0][0] <= VEC[high]) {
      IS_VISITED[0][0] = 1;
      q.push({0, 0});
    }

    while (!q.empty()) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 > nx || nx >= N || ny < 0 || ny >= N)
          continue;
        if (IS_VISITED[ny][nx])
          continue;
        if (VEC[low] <= CHART[ny][nx] && VEC[high] >= CHART[ny][nx]) {
          IS_VISITED[ny][nx] = true;
          q.push({ny, nx});
        }
      }
    }
    if (IS_VISITED[N - 1][N - 1]) {
      result = min(result, VEC[high] - VEC[low]);
      low++;
    } else if (high < VEC.size() - 1) {
      high++;
    } else {
      break;
    }
  }
  cout << result;
  return 0;
}