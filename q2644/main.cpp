#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, P1, P2, M;
vector<int> v[101];
bool is_visited[101];
void init()
{
  cin >> N;
  cin >> P1 >> P2;
  cin >> M;

  for (int i=0; i<M; i++) {
    int c, p;
    cin >> c >> p;
    v[c].push_back(p);
    v[p].push_back(c);
  }
}

void bfs()
{
  queue<pair<int, int> > q;
  q.push(make_pair(P1, 0));
  is_visited[P1] = true;

  while (!q.empty()) {
    int cur = q.front().first;
    int cnt = q.front().second;

    q.pop();

    if (cur == P2) {
      cout << cnt;
      return;
    }
    for (int i=0; i<v[cur].size(); i++) {
      int nxt = v[cur][i];

      if (is_visited[nxt]) {
        continue;
      }

      is_visited[nxt] = true;
      q.push(make_pair(nxt, cnt + 1));
    }
  }

  cout << -1;
}
int main()
{
  init();

  bfs();
  return 0;
}
