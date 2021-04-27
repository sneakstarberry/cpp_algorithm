#include <cmath>
#include <iostream>

using namespace std;

int main() {

  long long n, r, c;
  cin >> n >> r >> c;

  long long ans = 0;
  long long y = pow(2, n) / 2;
  long long x = y;

  while (n--) {
    long long temp = pow(2, n) / 2;
    long long skip = pow(4, n);

    if (r < y && c < x) {
      x -= temp;
      y -= temp;
    } else if (r < y && x <= c) {
      x += temp;
      y -= temp;
      ans += skip;
    } else if (y <= r && c < x) {
      x -= temp;
      y += temp;
      ans += skip * 2;
    } else {
      x += temp;
      y += temp;
      ans += skip * 3;
    }
  }
  cout << ans;
  return 0;
}