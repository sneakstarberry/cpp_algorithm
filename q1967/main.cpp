#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
#define MAX 10011
int N, MAX_LENGTH = 0, MOST_FAR_NODE;
vector<pair<int, int>> GRAPH[MAX];
int IS_VISITED[MAX];

void dfs(int node, int length) {
  if (MAX_LENGTH < length) {
    MAX_LENGTH = length;
    MOST_FAR_NODE = node;
  }
  for (int i = 0; i < GRAPH[node].size(); i++) {
    int n_node = GRAPH[node][i].first;
    int weight = GRAPH[node][i].second;

    if (!IS_VISITED[n_node]) {
      IS_VISITED[n_node] = 1;
      dfs(n_node, length + weight);
    }
  }
}

int main() {
  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int node, n_node, weight;
    cin >> node >> n_node >> weight;

    GRAPH[node].push_back({n_node, weight});
    GRAPH[n_node].push_back({node, weight});
  }
  memset(IS_VISITED, 0, sizeof(IS_VISITED));

  IS_VISITED[1] = 1;
  dfs(1, 0);

  memset(IS_VISITED, 0, sizeof(IS_VISITED));
  IS_VISITED[MOST_FAR_NODE] = 1;
  dfs(MOST_FAR_NODE, 0);

  cout << MAX_LENGTH;

  return 0;
}