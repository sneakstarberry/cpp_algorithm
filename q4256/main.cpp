#include <algorithm>
#include <iostream>

using namespace std;

int n;
int PRE[1001], IN[1001];

void post(int s, int e, int r) {
  for (int i = s; i < e; ++i) {
    if (IN[i] == PRE[r]) {
      post(s, i, r + 1);
      post(i + 1, e, r + 1 + i - s);
      cout << PRE[r] << ' ';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> PRE[i];
    for (int i = 0; i < n; ++i)
      cin >> IN[i];

    post(0, n, 0);
    cout << '\n';
  }
  return 0;
}