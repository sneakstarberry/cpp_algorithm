#include <iostream>
#include <queue>
#include <string>
#include <vector>


#define INF 51
using namespace std;

int N, M;
string miro[INF];
bool visited[64][INF][INF];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main() {
  cin >> N >> M;

  pair<int, int> start;

  for (int i = 0; i < N; i++) {
    cin >> miro[i];
    for (int j = 0; j < miro[i].length(); j++) {
      if(miro[i][j] == '0') {
        start.first = i;
        start.second = j;
      }
    }
  }

  queue<pair<pair<int,int>, pair<int,int>>> q;
  q.push({{start.first, start.second}, {0, 0}});
  visited[0][start.first][start.second] = true;

  while(!q.empty()) {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int cnt = q.front().second.first;
    int key = q.front().second.second;
    q.pop();

    if(miro[y][x] == '1') {
      cout << cnt;
      return 0;
    }

    for(int i=0;i<4;i++) {
      int next_y = y + dy[i];
      int next_x = x + dx[i];

      if(0<=next_y && next_y<N && 0<= next_x <M&& !visited[key][next_y][next_x] && miro[next_y][next_x]!='#') {
        if(miro[next_y][next_x] == '.' || miro[next_y][next_x] == '0' || miro[next_y][next_x] == '1') {
          visited[key][next_y][next_x] = true;
          q.push({{next_y, next_x}, {cnt+1, key}});
        } else if('a' <= miro[next_y][next_x] && miro[next_y][next_x] <= 'f' ) {
          int new_key = key | (1 << (int(miro[next_y][next_x])-97));

          if(!visited[new_key][next_y][next_x]) {
            visited[new_key][next_y][next_x] = true;
            q.push({{next_y, next_x}, {cnt+1, new_key}});
          }
        } else if('A' <= miro[next_y][next_x] && miro[next_y][next_x] <= 'F') {
          if(key & 1 << (int(miro[next_y][next_x]) - 65)) {
            visited[key][next_y][next_x] = true;
            q.push({{next_y, next_x}, {cnt+1, key}});
          }
        }
      }
    }
  }

  cout << -1;

  return 0;
}