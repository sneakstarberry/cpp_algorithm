#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Parents[100001];
int N;
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;
vector<pair<int, pair<int, int>>> INFO;

int find(int x) {
  if(Parents[x] == x) return x;
  else return Parents[x] = find(Parents[x]);
}

void Union (int x, int y) {
  x = find(x);
  y = find(y);

  if(x !=y) Parents[y] = x;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;

  for(int i=0;i<N;i++) {
    Parents[i] = i;
  }

  for(int i=0;i<N;i++) {
    int x,y,z;
    cin >> x >> y >> z;
    X.push_back({x, i});
    Y.push_back({y, i});
    Z.push_back({z, i});
  }

  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  sort(Z.begin(), Z.end());

  for(int i=0;i<N-1;i++) {
    INFO.push_back({abs(X[i+1].first - X[i].first) ,{X[i].second, X[i+1].second}});
    INFO.push_back({abs(Y[i+1].first - Y[i].first) ,{Y[i].second, Y[i+1].second}});
    INFO.push_back({abs(Z[i+1].first - Z[i].first) ,{Z[i].second, Z[i+1].second}});
  }
  sort(INFO.begin(), INFO.end());

  int total=0;

  for (int i=0;i<INFO.size();i++) {
    int a = INFO[i].second.first;
    int b = INFO[i].second.second;

    int v = INFO[i].first;

    if(find(a) != find(b)) {
      Union(a, b);
      total += v;
    }
  }
  cout << total;

  return 0;
}