#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF= 1e9+1;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  vector<pair<int, int>> vec;

  cin >> n;

  for (int i=0;i<n;i++) {
    int x,y;

    cin >> x >> y;
    vec.push_back({x, y});
  }

  sort(vec.begin(), vec.end());

  int length=0, s = -INF, e = -INF;

  for(int i=0; i<n;i++) {
    if(e < vec[i].first) {
      length += e - s;
      s = vec[i].first;
      e = vec[i].second;
    } else {
      e = max(vec[i].second, e);
    }
  }

  length += e-s;

  cout << length;

  return 0;
}