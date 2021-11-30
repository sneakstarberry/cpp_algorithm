#include <iostream>
#include <cmath>
using namespace std;

int N;
pair<int, int> point[3001];

void init() {
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> point[i].first >> point[i].second;
  }
}

void solve() {
  for (int i=0; i<N; i++) {
    int y = point[i].first;
    int x = point[i].second;

    int distance = abs(0-y) + abs(0-x);
    if (distance % 2 == 1) {
      cout << "-1 -1" << '\n';
      continue;
    }

    if (y % 2 == 1) {
      int c_y = ceil(y/2);
      int c_x = ceil(x/2) + 1;

      cout << c_y << ' ' << c_x << '\n';
    } else {
      cout << y/2 << ' ' << x/2 << '\n';
    }
  }
}


int main() {
  init();
  solve();

  return 0;
}
