#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 50000 + 1
#define endl '\n'
using namespace std;

int N, M, is_visited[MAX];
pair<vector<int>, int> NODE[MAX];
// depth를 매겨주기 위해서;
void bfs() {
  queue<pair<int, int>> q;
  q.push({1, 1});
  is_visited[1] = 1;

  while (!q.empty()) {
    int cur_node = q.front().first;
    int depth = q.front().second;
    NODE[cur_node].second = depth;
    q.pop();

    for (int i = 0; i < NODE[cur_node].first.size(); i++) {
      int next_node = NODE[cur_node].first[i];
      if (is_visited[next_node])
        continue;
      is_visited[next_node] = 1;
      q.push({next_node, depth + 1});
    }
  }
}
void lca(int node1, int node2) {
  int _node1 = NODE[node1].second < NODE[node2].second ? node2 : node1;
  int depth1 = max(NODE[node1].second, NODE[node2].second);
  int _node2 = NODE[node1].second < NODE[node2].second ? node1 : node2;
  int depth2 = min(NODE[node1].second, NODE[node2].second);

  for (int i = 0; i < depth1 - depth2; i++) {
    for (int j = 0; j < NODE[_node1].first.size(); j++) {
      int _node = NODE[_node1].first[j];
      if (NODE[_node].second < NODE[_node1].second) {
        _node1 = _node;
        break;
      }
    }
  }

  while (_node1 != _node2) {
    for (int i = 0; i < NODE[_node1].first.size(); i++) {
      int _node = NODE[_node1].first[i];
      if (NODE[_node].second < NODE[_node1].second) {
        _node1 = _node;
        break;
      }
    }
    for (int i = 0; i < NODE[_node2].first.size(); i++) {
      int _node = NODE[_node2].first[i];
      if (NODE[_node].second < NODE[_node2].second) {
        _node2 = _node;
        break;
      }
    }
  }
  cout << _node1 << endl;
}

int main() {
  cin >> N;
  for (int i = 1; i < N; i++) {
    int node1, node2;
    cin >> node1 >> node2;

    NODE[node1].first.push_back(node2);
    NODE[node2].first.push_back(node1);
  }

  bfs();

  cin >> M;

  while (M--) {
    int node1, node2;
    cin >> node1 >> node2;
    lca(node1, node2);
  }

  return 0;
}
