#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>


using namespace std;

int N, M;

int main() {

  cin >> N >> M;
  vector<int> vec[501];
  unordered_set<int> check;
  queue<int> q;

  for(int i=0; i<M; i++) {
    int a, b;
    cin >> a >> b;

    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  if(vec[1].empty()) {
    cout << 0;
    return 0;
  }

  for(int i=0; i< vec[1].size();i++) {
    q.push(vec[1][i]);
    check.insert(vec[1][i]);
  }

  while(!q.empty()) {
    int node = q.front();

    q.pop();
    for(int i=0;i<vec[node].size();i++) {
      check.insert(vec[node][i]);
    }
  }

  cout << check.size()-1;

  return 0;
}