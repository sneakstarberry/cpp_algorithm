#include <cmath>
#include <iostream>

#define MAX 10000 + 1
#define INF 987654321
using namespace std;
int is_node_parent[MAX], low[MAX], high[MAX], N, node_idx;
pair<int, int> node[MAX];

void DFS(int parent, int cnt) {

  if (node[parent].first > 0) {
    DFS(node[parent].first, cnt + 1);
  }

  low[cnt] = min(low[cnt], node_idx);
  high[cnt] = max(high[cnt], node_idx++);

  if (node[parent].second > 0) {
    DFS(node[parent].second, cnt + 1);
  }
}

int main() {
  int root;
  cin >> N;
  for (int i = 0; i < N + 1; i++) {
    low[i] = INF;
  }
  for (int i = 0; i < N; i++) {
    int parent, left, right;
    cin >> parent >> left >> right;
    is_node_parent[parent]++;
    if (left != -1)
      is_node_parent[left]++;
    if (right != -1)
      is_node_parent[right]++;
    node[parent] = make_pair(left, right);
  }

  for (int i = 0; i <= N; i++) {
    if (is_node_parent[i] == 1) {
      root = i;
    }
  }
  node_idx = 1;
  DFS(root, 1);

  int result = high[1] - low[1] + 1, level = 1;

  for (int i = 2; i < N + 1; i++) {
    int tmp = high[i] - low[i] + 1;
    if (result < tmp) {
      result = tmp;
      level = i;
    }
  }

  cout << level << ' ' << result << endl;
  return 0;
}