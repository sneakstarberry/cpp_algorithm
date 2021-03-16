#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 101
#define INF 987654321
using namespace std;


int dist[MAX][MAX];
int n, m;
int arr[MAX][MAX];
queue<pair<int, int>> q;
int dist_x[4] = {0, 1, 0, -1};
int dist_y[4] = {1,0, -1, 0};

void Print();

int main() {
  ios_base::sync_with_stdio(0);

  cin.tie(0);
  for(int i=0; i<MAX; i++) {
    for(int j=0; j<MAX; j++) {
      dist[i][j] = INF;
    }
  }
  dist[0][0] = 0;

  cin >> m;
  cin >> n;
  for(int i=0; i<n; i++) {
    string tmp;
    cin >> tmp;
    for(int j=0; j<tmp.length(); j++) {
      arr[i][j] = tmp[j] - '0';
    }
  }

  q.push({0, 0});

  while(!q.empty()) {
    int curr_x = q.front().first;
    int curr_y = q.front().second;
    q.pop();

    for(int i=0; i<4; i++) {
      int n_x = curr_x + dist_x[i];
      int n_y = curr_y + dist_y[i];


      if( 0<=n_x && n_x < m && 0<=n_y && n_y <n){
        int cost = arr[n_y][n_x];
        if(dist[n_y][n_x] <= dist[curr_y][curr_x] + cost) continue;
        dist[n_y][n_x] = dist[curr_y][curr_x] + cost;
        q.push({n_x, n_y});
      } else {
        continue;
      }
    }
  }

  std::cout << dist[n-1][m-1];

  return 0;
}

void Print() {
  cout << "###################################" << endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cout << dist[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << "###################################" << endl;
}