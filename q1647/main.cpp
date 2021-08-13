#include <algorithm>
#include <iostream>
#include <vector>

#define INF 100000 + 1
#define endl '\n'

using namespace std;

int N, M;
int Parent[INF];
vector<pair<int, pair<int, int>>> Edge;

int Find(int x) {
  if (Parent[x] != x)
    return Parent[x] = Find(Parent[x]);
  else
    return x;
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);

  if (x != y)
    Parent[y] = x;
}

bool isSameParent(int x, int y) {
  x = Find(x);
  y = Find(y);

  if (x != y)
    return false;
  else
    return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  int answer = 0, last;

  for (int i = 0; i < M; i++) {
    int a, b, c;

    cin >> a >> b >> c;

    Edge.push_back(make_pair(c, make_pair(a, b)));
  }

  for (int i = 1; i <= N; i++) {
    Parent[i] = i;
  }

  sort(Edge.begin(), Edge.end());

  for (int i = 0; i < M; i++) {
    if (isSameParent(Edge[i].second.first, Edge[i].second.second) == false) {
      Union(Edge[i].second.first, Edge[i].second.second);
      answer += Edge[i].first;
      last = Edge[i].first;
    }
  }

  cout << answer - last << endl;

  return 0;
}