#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX 1001
using namespace std;

int N, M;
int S, E;
int DIST[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;

int main() {
  int from, to, cost;
  cin >> N >> M;
  vector<pair<int, int>> cities[MAX];

  for(int i=1; i<=M; i++) {
    cin >> from >> to >> cost;
    cities[from].push_back(make_pair(to, cost));
  }
  for(int i=1; i<=N; i++) {
    DIST[i] = INF;
  }

  cin >> S >> E;
  DIST[S] = 0;

  PQ.push({0, S});

  while(!PQ.empty()) {
    int cost = PQ.top().first;
    int curr = PQ.top().second;

    PQ.pop();

    for(int i=0; i<cities[curr].size(); i++){
      int to = cities[curr][i].first;
      int n_cost = cities[curr][i].second;

      if(DIST[to] <= cost + n_cost) {
        continue;
      }

      DIST[to] = cost + n_cost;
      PQ.push({DIST[to], to});
      
    }
  }

  cout << DIST[E];
  return 0;
}