#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, pair<int, int>>> Edge;
int Parent[100001];

int Find(int x) {
  if(Parent[x] == x) return x;
  else return Parent[x] = Find(Parent[x]);
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);

  if(x !=y) Parent[y] = x;
}

bool SameParent(int x, int y) {
  x = Find(x);
  y = Find(y);

  if(x==y) return true;
  else return false;
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int answer = 0;

  cin >> N >> M;

  for(int i=0;i<M;i++) {
    int a, b,c;

    cin >> a >> b >> c;

    Edge.push_back(make_pair(c, make_pair(a, b)));
  }

  sort(Edge.begin(), Edge.end());
  for(int i=1; i<=N; i++) {
    Parent[i] = i;
  }

  for (int i=0;i<M;i++) {
    if(SameParent(Edge[i].second.first, Edge[i].second.second) == false) {
      Union(Edge[i].second.first, Edge[i].second.second);
      answer = answer + Edge[i].first;
    }
  }

  cout << answer << endl;



  return 0;
}