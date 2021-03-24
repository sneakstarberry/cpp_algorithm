#include <iostream>
#include <vector>

using namespace std;

void solution();
int is_domino_place(int k1, int k2, int n, int w, int b);

int main() {
  int t;

  cin >> t;

  while (t--) {
    solution();
  }

  return 0;
}

void solution() {
  int n, k1, k2;
  int w, b;
  vector<int> vec1;
  vector<int> vec2;
  cin >> n >> k1 >> k2;
  cin >> w >> b;

  if (is_domino_place(k1, k2, n, w, b)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int is_domino_place(int k1, int k2, int n, int w, int b) {
  int white = k1 + k2;
  int black = n * 2 - white;
  if (white / 2 >= w && black / 2 >= b) {
    return 1;
  } else {
    return 0;
  }
}