#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 100000001

using namespace std;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, d;
  int high = 0;
  vector<pair<int,int>> vec;

  cin >> n;

  for(int i=0; i<n;i++) {
    int h, o;
    cin >> h >> o;
    if(h<o) {
      vec.push_back({o, h});
    } else {
      vec.push_back({h, o});
    }
  }

  cin >> d;

  sort(vec.begin(), vec.end());

  priority_queue<int> pq;

  for(int i=0; i<n;i++) {
    pq.push(-vec[i].second);

    while(!pq.empty() && -pq.top() < vec[i].first - d) pq.pop();

    int size = pq.size();

    high = max(size, high);

  }


  cout << high;

  return 0;
}