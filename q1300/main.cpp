#include <algorithm>
#include <iostream>

using namespace std;

long long N, K;

void solve();

int main() {
  cin >> N >> K;

  solve();
  return 0;
}

void solve() {
  long long l, h, m, ans = 1;
  long long cnt = 0;

  h = K + 1;
  l = -1;
  while (l + 1 < h) {
    m = (h + l) / 2;
    cnt = 0;

    for (long long i = 1; i <= N; i++) {
      cnt += min(N, m / i);
    }

    if (cnt < K) {
      l = m;
    } else {
      ans = m;
      h = m;
    }
  }
  cout << ans;
}