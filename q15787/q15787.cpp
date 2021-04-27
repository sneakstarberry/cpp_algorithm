#include <cstring>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m;
  int trains[100000 + 1];
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int code, train_num, seat;
    cin >> code >> train_num;

    if (code == 1) {
      cin >> seat;
      trains[train_num] |= 1 << (seat - 1);
    } else if (code == 2) {
      cin >> seat;
      trains[train_num] &= ((1 << 20) - 1) - (1 << (seat - 1));
    } else if (code == 3) {
      trains[train_num] = (trains[train_num] << 1) & ((1 << 20) - 1);
    } else if (code == 4) {
      trains[train_num] = trains[train_num] >> 1;
    }
  }

  int cnt = 0;
  int passed[1 << 20] = {
      0,
  };
  for (int i = 1; i <= n; i++) {
    if (passed[trains[i]] == 0) {
      passed[trains[i]] = 1;
      cnt++;
    }
  }

  cout << cnt;

  return 0;
}