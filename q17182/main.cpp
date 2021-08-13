#include <iostream>

using namespace std;

int N, K, planets[11][11];
bool is_visited[11] = {false,};

int ANS = 987654321;

void dfs(int start, int dist, int cnt);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;

  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      cin >> planets[i][j];
    }
  }

  for(int k=0; k<N;k++) {
    for(int i=0;i<N;i++) {
      for(int j=0;j<N;j++) {
        if(planets[i][k] + planets[k][j] < planets[i][j]) {
          planets[i][j] = planets[i][k] + planets[k][j];
        }
      }
    }
  }

  dfs(K, 0, 0);

  cout << ANS;

  return 0;
}

void dfs(int start, int dist, int cnt) {
  if(ANS < dist) return;

  if(cnt == N) {
    ANS = dist;
    return;
  }

  for(int i=0;i<N;i++) {
    if(is_visited[i]) continue;
    is_visited[i] = true;
    dfs(i, dist + planets[start][i], cnt+1);
    is_visited[i] = false;
  }
}