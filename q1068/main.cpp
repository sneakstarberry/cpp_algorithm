#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> vec[51];
int is_visited[51];

int main() {
  int n, root, del, cnt = 0;
  queue<int> q;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (tmp == -1) {
      root = i;
    } else {
      vec[tmp].push_back(i);
    }
  }
  cin >> del;
  memset(is_visited, 0, sizeof(is_visited));
  q.push(root);
  is_visited[root] = 1;
  is_visited[del] = 1;
  if (root == del) {
    cout << 0;
    return 0;
  }
  while (!q.empty()) {
    int current_node = q.front();
    is_visited[current_node] = 1;
    q.pop();

    if (!vec[current_node].size()) {
      cnt++;
    }
    for (int i = 0; i < vec[current_node].size(); i++) {
      if (vec[current_node].size() == 1 && vec[current_node][i] == del) {
        cnt++;
      }
      if (is_visited[vec[current_node][i]])
        continue;
      q.push(vec[current_node][i]);
    }
  }
  cout << cnt;
  return 0;
}