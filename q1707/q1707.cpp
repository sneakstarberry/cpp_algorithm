#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int K, V, E;
vector<int> VEC[20001];
int IS_VISITED[20001];

// state
// none = 0;
// red = 1;
// blue = 2;

void bfs();

int main() {
  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> V >> E;
    if (V * V < E) {
      cout << "NO" << endl;
    }
    for (int j = 0; j < E; j++) {
      int from, to;
      cin >> from >> to;

      VEC[from].push_back(to);
      VEC[to].push_back(from);
    }
    bfs();
    for (int k = 1; k <= V; k++) {
      VEC[k].clear();
    }
  }
}

void bfs() {
  memset(IS_VISITED, 0, sizeof(IS_VISITED));
  for (int i = 1; i <= V; i++) {
    if (IS_VISITED[i]) {
      continue;
    }
    queue<int> q;
    q.push(i);
    IS_VISITED[i] = 1;
    while (!q.empty()) {
      int node = q.front();
      int color = IS_VISITED[node];

      q.pop();

      for (int j = 0; j < VEC[node].size(); j++) {
        int next = VEC[node][j];
        int n_color = IS_VISITED[next];

        if (!n_color) {
          int decide_color = color == 1 ? 2 : 1;
          IS_VISITED[next] = decide_color;
          q.push(next);
        } else if (n_color == color) {
          std::cout << "NO" << endl;
          return;
        }
      }
    }
  }
  std::cout << "YES" << endl;
  return;
}
