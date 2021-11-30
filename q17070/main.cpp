#include <iostream>
#include <queue>
using namespace std;

int N, CNT=0;
int H[17][17];

void vertical(pair<int, int> cur, queue<pair<int, pair<int, int > > > &q);
void horizontal(pair<int, int> cur, queue<pair<int, pair<int, int > > > &q);
void diagonal(pair<int, int> cur, queue<pair<int, pair<int, int > > > &q);

int main()
{
  queue<pair<int, pair<int, int> > > q;
  
  cin >> N;

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cin >> H[i][j];
    }
  }
  q.push(make_pair(0, make_pair(0, 1)));
  while (!q.empty()) {
    int state = q.front().first;
    int y = q.front().second.first, x = q.front().second.second;
    q.pop();

    if (y == (N-1) && x == (N-1)) {
      CNT++;
    }
    
    switch (state) {
    case 0:
      horizontal(make_pair(y, x), q);
      diagonal(make_pair(y, x), q);
      break;
    case 1:
      vertical(make_pair(y, x), q);
      diagonal(make_pair(y, x), q);
      break;
    case 2:
      diagonal(make_pair(y, x), q);
      horizontal(make_pair(y, x), q);
      vertical(make_pair(y, x), q);
      break;
    }
  }

  cout << CNT;
  
  return 0;
}

void horizontal(pair<int, int> cur, queue<pair<int, pair<int, int > > > &q) {
  int n_y = cur.first, n_x = cur.second + 1;

  if (n_x < N && H[n_y][n_x] == 0) {
    q.push(make_pair(0, make_pair(n_y, n_x)));
  }
}

void vertical(pair<int, int> cur, queue<pair<int, pair<int, int > > > &q) {
  int n_y = cur.first + 1, n_x = cur.second;

  if (n_y < N && H[n_y][n_x] == 0) {
    q.push(make_pair(1, make_pair(n_y, n_x)));
  }
}

void diagonal(pair<int, int> cur, queue<pair<int, pair<int, int > > > &q) {
  int n_y = cur.first + 1, n_x = cur.second + 1;

  if(n_y < N && n_x < N && H[n_y][n_x] == 0 && H[n_y-1][n_x] == 0 && H[n_y][n_x - 1] == 0) {
    q.push(make_pair(2, make_pair(n_y, n_x)));
  }
}
