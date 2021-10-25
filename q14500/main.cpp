#include <iostream>
#include <vector>

using namespace std;

int N, M, MAX = 0;
vector<vector<int>> paper;
bool is_visited[501][501] = {
    false,
};

struct Tetromino {
  int n, m;
  vector<vector<int>> map;

  Tetromino(int n, int m) : n(n), m(m) {
    vector<int> tmp1 = {0, 1, 0};
    vector<int> tmp2 = {1, 1, 1};

    map.push_back(tmp1);
    map.push_back(tmp2);
  }

  void rotate() {
    int tmp_n = m;
    int tmp_m = n;
    vector<vector<int>> tmp_map(tmp_n, vector<int>(tmp_m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        tmp_map[j][n - i - 1] = map[i][j];
      }
    }

    n = tmp_n;
    m = tmp_m;

    map = tmp_map;
  }
};

void dfs(pair<int, int> point, int sum, int cnt) {
  if (cnt == 4) {
    if (MAX < sum) {
      MAX = sum;
    }
    return;
  }

  for (int i = 0; i < 4; i++) {
    int n_y = point.first + "2101"[i] - '1';
    int n_x = point.second + "1210"[i] - '1';

    if (!(0 <= n_y && n_y < N && 0 <= n_x && n_x < M))
      continue;
    if (is_visited[n_y][n_x])
      continue;
    is_visited[n_y][n_x] = true;
    dfs(make_pair(n_y, n_x), sum + paper[n_y][n_x], cnt + 1);
    is_visited[n_y][n_x] = false;
  }
};

void mapping(pair<int, int> point) {
  Tetromino tetromino(2, 3);

  for (int k = 0; k < 4; k++) {
    int sum = 0;
    for (int i = 0; i < tetromino.n; i++) {
      for (int j = 0; j < tetromino.m; j++) {
        if (tetromino.map[i][j] == 1 && 0 <= point.first + i &&
            point.first + i < N && 0 <= point.second + j &&
            point.second + j < M) {
          sum += paper[point.first + i][point.second + j];
        } else {
          continue;
        }
      }
    }
    tetromino.rotate();
    if (MAX < sum) {
      MAX = sum;
    }
  }

  return;
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  paper = vector<vector<int> >(N, vector<int>(M, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> paper[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      is_visited[i][j] = true;
      dfs(make_pair(i, j), paper[i][j], 1);
      is_visited[i][j] = false;
      mapping(make_pair(i,j));
    }
  }

  cout << MAX << "\n";

  return 0;
}
