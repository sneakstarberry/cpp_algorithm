#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int T;

bool dsc(pair<int,int> a, pair<int, int>b) {
  return a.second > b.second;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;

  while(T--) {
    int n, m;
    vector<pair<int, int>> answer;
    cin >> n;
    vector<pair<int,int>> vec;

    vec.push_back({0,0});

    for(int i=0;i<n;i++) {
      int x, y;
      cin >> x >> y;
      if(x == 0 && y == 0) {
        continue;
      }

      vec.push_back({x, y});
    }

    sort(vec.begin()+1, vec.end());

    for(int i=1;i<n;i++) {
      int cnt = 1;
      bool reverse = false;
      if(i == 1 && vec[i].first == 0 && vec[i].second < 0){
        reverse = true;

        while(vec[i].first == vec[i+cnt].first && vec.begin()+i+cnt != vec.end()) {
          cnt++;
        }
      }

      if(vec[i].first != vec[i-1].first && vec[i].second != vec[i-1].second) {
        reverse = true;

        while(vec[i].first == vec[i+cnt].first && vec.begin()+i+cnt != vec.end()) {
          cnt++;
        }
      }

      if(reverse) {
        sort(vec.begin()+i, vec.begin()+i+cnt, dsc);
      }

      i+=cnt-1;
    }

    cin >> m;

    for(int i=0;i<m;i++) {
      int k;
      cin >> k;

      cout << vec[k-1].first << ' ' << vec[k-1].second << '\n';
    }
  }

  return 0;
}