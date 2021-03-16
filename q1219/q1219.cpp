#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define INF 1LL << 60
#define MAX 101
using namespace std;

typedef struct Edge {
  int from;
  int to;
  long long cost;
} Edge;

int N, S, E, M;
vector<Edge> VEC;
long long DIST[MAX], EARN[MAX];
int is_visited[MAX];

void input();
void bf();
int bfs(int start);

int main() {

  input();
  bfs(S);
  DIST[S] = -EARN[S];
  bf();

  if (DIST[E] != INF)
    cout << -DIST[E];

  return 0;
}

void input() {
  cin >> N >> S >> E >> M;

  for (int i = 0; i < M; i++) {
    Edge edge;
    cin >> edge.from >> edge.to >> edge.cost;
    VEC.push_back(edge);
  }

  for (int i = 0; i < N; i++) {
    DIST[i] = INF;
    cin >> EARN[i];
  }
}

void bf() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int from = VEC[j].from;
      int to = VEC[j].to;
      long long cost = VEC[j].cost;

      if (DIST[from] == INF) {
        continue;
      }
      if (DIST[to] > DIST[from] + (cost - EARN[to])) {
        DIST[to] = DIST[from] + (cost - EARN[to]);
        if (i == (N - 1) && bfs(to)) {
          cout << "Gee";
          exit(0);
        }
      }
    }
  }
}

int bfs(int start) {
  memset(is_visited, 0, sizeof(is_visited));
  int flag = 0;

  queue<int> q;
  q.push(start);
  is_visited[start] = 1;

  while (!q.empty()) {
    int node = q.front();

    q.pop();

    for (int i = 0; i < M; i++) {
      if (VEC[i].from != node)
        continue;
      if (!is_visited[VEC[i].to]) {
        is_visited[VEC[i].to] = 1;

        q.push(VEC[i].to);
      }
    }
  }
  if (!is_visited[E]) {
    flag = 1;
    if (start == S) {
      cout << "gg";
      exit(0);
    }
  }
  if (flag) {
    return 0;
  }
  return 1;
}