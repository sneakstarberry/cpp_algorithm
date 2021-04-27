#include <iostream>
#include <string.h>
#include <vector>

#define MAX 100111
#define endl '\n'
using namespace std;

int IS_VISITED[MAX], V, MAX_LENGTH = 0;
vector<pair<int, int>> GRAPH[MAX];

void dfs(int node, int length);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> V;
  memset(IS_VISITED, 0, sizeof(IS_VISITED));
  for (int i = 1; i <= V; i++) {
    int node = 0, idx, distance;
    cin >> idx;

    while (1) {
      cin >> node;
      if (node == -1)
        break;
      cin >> distance;
      GRAPH[idx].push_back({node, distance});
    }
  }

  for (int i = 1; i <= V; i++) {
    memset(IS_VISITED, 0, sizeof(IS_VISITED));
    dfs(i, 0);
  }

  cout << MAX_LENGTH << endl;
}

void dfs(int node, int length) {
  if (IS_VISITED[node])
    return;
  IS_VISITED[node] = 1;
  if (MAX_LENGTH < length) {
    MAX_LENGTH = length;
  }

  for (int i = 0; i < GRAPH[node].size(); i++) {
    int next = GRAPH[node][i].first;
    int weight = GRAPH[node][i].second;
    dfs(next, length + weight);
  }
}
