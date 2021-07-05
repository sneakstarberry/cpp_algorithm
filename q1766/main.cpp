#include<iostream>
#include<vector>
#include<queue>

#define MAX 32001
using namespace std;

int main() {
  int n, m;
  vector<int> vec[MAX];
  int arr[MAX];
  priority_queue<int, vector<int>, greater<int>> pq;

  cin >> n >> m;

  for(int i=0;i<m;i++) {
    int v1, v2;

    cin >> v1 >> v2;

    vec[v1].push_back(v2);
    arr[v2]++;
  }

  for(int i=1;i<n+1;i++) {
    if(arr[i] == 0) {
      pq.push(i);
    }
  }

  for(int i=0;i<n;i++) {
    int v = pq.top();

    pq.pop();

    cout << v << ' ';

    for(int j=0;j<vec[v].size();j++) {
      arr[vec[v][j]]--;
      if(arr[vec[v][j]]==0) {
        pq.push(vec[v][j]);
      }
    }
  }

  return 0;
}