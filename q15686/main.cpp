#include <iostream>
#include <vector>
#include <math.h>
#define INF (1<<31) - 1
using namespace std;

int N, M, RST = INF;
vector<pair<int, int> > Chickens;
bool is_visited[14] = {
    0,
};
vector<pair<int, int> > CurChickens;
vector<pair<int, int> > House;
int MAP[51][51] = {
    0,
};

int manhattan(pair<int, int> a, pair<int, int> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
};

void bt(int idx, int cnt) {
  if(cnt == M) {
    int tmpRst = 0;
    for (int i=0; i<House.size(); i++) {
      int dist = INF;
      for (int j=0; j<CurChickens.size(); j++) {
	dist = min(dist, manhattan(House[i], CurChickens[j]));
      }
      tmpRst +=dist;
    }
    RST = min(RST, tmpRst);    
    return;
  }

  for (int i=idx; i<Chickens.size(); i++) {
    if(is_visited[i]) continue;
    is_visited[i] = true;
    CurChickens.push_back(Chickens[i]);
    bt(i, cnt+1);
    CurChickens.pop_back();
    is_visited[i] = false;
  }

};
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cin >> MAP[i][j];
      if(MAP[i][j] == 2) {
	Chickens.push_back(make_pair(i, j));
      } else if(MAP[i][j] == 1) {
	House.push_back(make_pair(i, j));
      }
    }
  }

  bt(0, 0);

  cout << RST << '\n';

  return 0;
}
