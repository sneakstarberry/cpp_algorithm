#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int n, m;
  vector<int> answer;
  vector<int> vec[1001];
  int arr[1001];
  queue<int> q;

  cin >> n >> m;

  for(int i=0;i<m;i++) {
    int num;

    cin >> num;
    vector<int> sub;
    for(int j=0;j<num;j++) {
      int tmp;
      cin >> tmp;
      sub.push_back(tmp);
    }

    for(int j=1;j<sub.size();j++) {
      vec[sub[j-1]].push_back(sub[j]);
      arr[sub[j]]++;
    }
  }

  for(int i=1;i<n+1;i++) {
    if(arr[i] == 0) {
      q.push(i);
    }
  }

  for(int i=0;i<n;i++) {
    if(q.empty()) {
      cout << 0;
      return 0;
    }
    int v = q.front();
    q.pop();

    answer.push_back(v);

    for(int j=0;j<vec[v].size();j++) {
      arr[vec[v][j]]--;

      if(arr[vec[v][j]] == 0) {
        q.push(vec[v][j]);
      }
    }
  }

  for(int i=0; i<answer.size();i++) {
    cout << answer[i] << '\n';
  }

  return 0;
}