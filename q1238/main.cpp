#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 1001
#define INF 987654321

using namespace std;

int N, M, X;
vector<int> DIST(MAX, 0);
int RES[MAX];
vector<pair<int, int>> V[MAX];

void dj(int start) {
  priority_queue<pair<int, int>> pq;

  pq.push({0, start});
  DIST[start] = 0;

  while (!pq.empty()) {
    int cost = -pq.top().first;
    int cur = pq.top().second;

    pq.pop();

    for (int i = 0; i < V[cur].size(); i++) {
      int nxt = V[cur][i].first;
      int nxt_cost = V[cur][i].second;

      if (DIST[nxt] > cost + nxt_cost) {
        DIST[nxt] = cost + nxt_cost;
        pq.push({-DIST[nxt], nxt});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);

  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> X;

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    V[a].push_back({b, c});
  }

  for (int i = 1; i <= N; i++) {
    for (int i = 1; i <= N; i++) {
      DIST[i] = INF;
    }
    dj(i);
    RES[i] = DIST[X];
  }

  for (int i = 1; i <= N; i++) {
    DIST[i] = INF;
  }

  dj(X);

  int highest = 0, num;
  for (int i = 1; i <= N; i++) {
    if (highest < DIST[i]+RES[i]) {
      highest = DIST[i]+RES[i];
    }
  }

  cout << highest << endl;

  return 0;
}