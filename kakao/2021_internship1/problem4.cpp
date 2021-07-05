#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int graph[1001][1001];
int is_visited[1001];
int MIN_PRICE = 987654321;

int is_trap(int node, vector<int> traps) {
  for (int i = 0; i < traps.size(); i++) {
    if (traps[i] == node) {
      return 1;
    }
  }
  return 0;
}

void convert(int n, int node) {
  for (int i = 1; i <= n; i++) {
    if (graph[i][node]) {
      graph[node][i] = graph[i][node];
      graph[i][node] = 0;
      is_visited[i] = 0;
    }
  }
}

void dfs(int n, int end, int node, int total_price, vector<int> traps) {
  if (node == end) {
    MIN_PRICE = min(MIN_PRICE, total_price);
    return;
  }
  if (is_trap(node, traps)) {
    convert(n, node);
  }

  for (int i = 1; i <= n; i++) {
    if (!graph[node][i])
      continue;
    if (is_visited[i])
      continue;
    is_visited[i] = 1;
    total_price += graph[node][i];
    dfs(n, end, i, total_price, traps);
    is_visited[i] = 0;
  }
}

int solution(int n, int start, int end, vector<vector<int>> roads,
             vector<int> traps) {
  int answer = 0;
  for (int i = 0; i < 1001; i++) {
    memset(graph[i], 0, sizeof(graph[i]));
  }
  memset(is_visited, 0, sizeof(is_visited));

  for (int i = 0; i < roads.size(); i++) {
    int from, to, price;
    from = roads[i][0];
    to = roads[i][1];
    price = roads[i][2];

    graph[from][to] = price;
  }
  is_visited[start] = 1;
  dfs(n, end, start, 0, traps);

  answer = MIN_PRICE;
  return answer;
}

int main() {
  int n = 4;
  int start = 1;
  int end = 4;
  vector<vector<int>> roads = {{1, 2, 1}, {3, 2, 1}, {2, 4, 1}};
  vector<int> traps = {2, 3};

  cout << solution(n, start, end, roads, traps);

  return 0;
}