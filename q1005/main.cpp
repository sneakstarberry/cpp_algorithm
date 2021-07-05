#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T, N, K, D;

int main() {
  cin >> T;
  while (T--) {
    cin >> N >> K;
    queue<int> q;
    vector<int> w(N + 1);
    vector<int> graph[1001];
    vector<int> indegree(N + 1);
    vector<int> result(N + 1);

    for (int i = 1; i <= N; i++) {
      cin >> w[i];
    }

    for (int i = 0; i < K; i++) {
      int from, to;
      cin >> from >> to;
      graph[from].push_back(to);
      indegree[to]++;
    }
    cin >> D;

    for (int i = 1; i <= N; i++) {
      if (!indegree[i]) {
        result[i] = w[i];
        q.push(i);
      }
    }

    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int i = 0; i < graph[v].size(); i++) {
        result[graph[v][i]] =
            max(result[graph[v][i]], result[v] + w[graph[v][i]]);
        if (--indegree[graph[v][i]] == 0) {
          q.push(graph[v][i]);
        }
      }
    }

    cout << result[D] << '\n';
  }
  return 0;
}
