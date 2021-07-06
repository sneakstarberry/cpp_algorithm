#include <iostream>
#include <vector>

#define INF 101

using namespace std;

int X, Y, N, D, G, RST;

int END_X, END_Y;

bool map[INF][INF];

int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};

vector<int> DRG;

void make_generation(vector<int> &dragon) {
  int size = dragon.size();

  for (int i=size-1; i>=0; i--) {
    int dir = (dragon[i] +1) % 4;

    END_X = END_X + dx[dir];
    END_Y = END_Y + dy[dir];

    map[END_X][END_Y] = true;

    dragon.push_back(dir);
  }
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for(int i=0;i<N;i++) {
    cin >> Y >> X >> D >> G;

    DRG.clear();
    map[X][Y] = true;

    END_X = X + dx[D];
    END_Y = Y + dy[D];

    map[END_X][END_Y] = true;

    DRG.push_back(D);

    for(int i=0;i<G;i++) {
      make_generation(DRG);
    }
  }

  for(int i=0; i<INF-1;i++) {
    for(int j=0; j<INF-1; j++) {
      if(map[i][j] == true && map[i][j+1] == true && map[i+1][j] == true && map[i+1][j+1]) {
        RST++;
      }
    }
  }

  cout << RST;

  return 0;
}
