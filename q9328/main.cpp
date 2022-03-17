#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int T, H, W;
int key[26];
int visited[102][102];
int docs;
string map[102];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void BFS(int y, int x) {
  queue<pair<int, int> > q;
  q.push(make_pair(y, x));

  while(!q.empty()) {
    int cur_y = q.front().first;
    int cur_x = q.front().second;
    q.pop();

    if(cur_y < 0 || cur_y > H + 1 || cur_x < 0 || cur_x > W + 1) continue;

    if(visited[cur_y][cur_x] || map[cur_y][cur_x] == '*' || ('A' <= map[cur_y][cur_x] && map[cur_y][cur_x] <= 'Z')) continue;

    
    visited[cur_y][cur_x] = 1;

    if (map[cur_y][cur_x] == '$') {
      docs++;
      map[cur_y][cur_x] = '.';
    }

    if('a' <= map[cur_y][cur_x] && map[cur_y][cur_x] <= 'z') {
      char door = (char)toupper(map[cur_y][cur_x]);
      map[cur_y][cur_x] = '.';

      if (key[(int)door - 65] == 0) {
	key[(int)door - 65] = true;

	for (int y = 1; y<=H; y++) {
	  for (int x = 1; x<=W; x++) {
	    if (map[y][x] == door) {
	      map[y][x] = '.';
	    }
	  }
	}
	memset(visited, false, sizeof(visited));

	while(!q.empty()) q.pop();
	q.push(make_pair(cur_y, cur_x));
	continue;
      }
    }
    for (int i=0; i<4; i++) {
      int next_y = cur_y + dy[i];
      int next_x = cur_x + dx[i];

      q.push(make_pair(next_y, next_x));
    }
  }
}

int main()
{
  cin >> T;

  while (T--) {
    memset(key, 0, sizeof(key));

    for (int j=0; j< 102; j++) {
      map[j].clear();
    }
    memset(visited, false, sizeof(visited));
    cin >> H >> W;

    for (int j=0; j<W+2; j++) {
      map[0]+='.';
    }

    for (int j=1; j<=H; j++) {
      string tmp;
      cin >> tmp;
      map[j] += '.';
      map[j] += tmp;
      map[j] +='.';
    }
    for (int j=0; j<W+2; j++) {
      map[H+1] += '.';
    }

    string alphabet;
    cin>> alphabet;

    for (int j=0; alphabet[j]!='0' && j<alphabet.length(); j++) {
      key[(int)alphabet[j] - 97] = true;
      for (int y=1; y<=H; y++) {
        for (int x = 1; x<=W; x++) {
	  if (map[y][x] == (char)toupper(alphabet[j])) {
	    map[y][x] = '.';
	  }
	}
      }
    }

    docs = 0;
    BFS(0, 0);
    cout << docs << endl;
  }
  return 0;
}
