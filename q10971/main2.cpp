#include <stack>
#include <iostream>

using namespace std;

int N, cities[11][11];
int ANS = (1 << 31) - 1;

struct Temp {
  int cur, dist, is_visited, cnt;
};

void dfs(int start) {
  stack<Temp> s;
  s.push({start, 0,0,0});

  while(!s.empty()) {
    Temp temp = s.top();
    s.pop();

    if(ANS < temp.dist) continue;

    if(temp.cnt == N && temp.cur == start) {
      if (ANS > temp.dist) {
        ANS = temp.dist;
      }
      continue;
    }

    for(int i=0;i<N;i++) {
      if(((temp.is_visited & (1<<i)) != 0) || cities[temp.cur][i] == 0) continue;

      s.push({i, temp.dist + cities[temp.cur][i], (temp.is_visited | (1<<i)), temp.cnt + 1});
    }
  }

  return;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for(int i=0; i<N;i++) {
    for(int j=0;j<N;j++) {
      cin >> cities[i][j];
    }
  }

  for(int i=0;i<N;i++) {
    dfs(i);
  }

  cout << ANS;
  return 0;
}