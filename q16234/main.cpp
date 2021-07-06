#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int N, L, R;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  std::cout.tie(0);

  vector<int> map[51];
  int ans = 0;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};

  cin >> N >> L >> R;
  
  for(int i=0; i<N;i++) {
    for(int j=0;j<N;j++) {
      int tmp;
      cin >> tmp;
      map[i].push_back(tmp);
    }
  }

  bool flag = true;

  while(flag) {
    queue<int> q;
    bool visited[10001] = {false, };
    flag = false;

    ans++;

    for(int i=0;i<N*N;i++) {
      if(visited[i]) {
        continue;
      }

      vector<int> track;

      int r = i/N;
      int c = i%N;
      q.push(i);
      visited[i] = true;
      track.push_back(i);
      int total = map[r][c];
      int n = 1;

      while(!q.empty()) {
        int v = q.front();
        q.pop();
        r = v/N;
        c = v%N;

        for(int k=0; k<4; k++) {
          int nx = c + dx[k];
          int ny = r + dy[k];

          if( 0<=nx && nx < N && 0 <= ny && ny < N) {
            int next = ny * N + nx;

            if (visited[next]) {
              continue;
            }

            int count = map[ny][nx];
            int pivot = map[r][c];
            if(L <= abs(count - pivot) && abs(count - pivot) <= R) {
              flag = true;
              q.push(next);
              visited[next] = true;
              track.push_back(next);
              total += map[ny][nx];
              n++;
            }
          }
        }
      }

      int update = floor(total/n);
      if(track.size() > 1) {
        for(auto v: track) {
          r = v/N;
          c = v%N;
          map[r][c] = update;
        }
      }
    }
  }

  std::cout << ans - 1;

  return 0;
}