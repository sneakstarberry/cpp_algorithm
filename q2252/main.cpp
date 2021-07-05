#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> VEC[32001];
int arr[32001];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;

    VEC[v1].push_back(v2);
    arr[v2]++;
  }

  queue<int> q;

  for (int i = 1; i < n+1; i++) {
    if (arr[i]==0) {
      q.push(i);
    }
  }

  for (int i = 0; i < n; i++) {
    int v = q.front();
    q.pop();
    cout << v << ' ';

    for (int j = 0; j < VEC[v].size(); j++) {
      arr[VEC[v][j]]--;
      if (arr[VEC[v][j]] == 0) {
        q.push(VEC[v][j]);
      }
    }
  }

  return 0;
}