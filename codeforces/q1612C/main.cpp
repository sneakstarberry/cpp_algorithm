#include <iostream>

using namespace ::std;

int N;
typedef long long ll;
pair<ll, ll> limits[10001];

void init() { cin >> N; }

ll sum(ll start, ll end) {
  return ((start + end) * end) / 2;
}

void solve() {
  while (N--) {
    ll k, x;
    cin >> k >> x;

    ll half = ((1 + k) * k) /2;
    ll half2 = half - k;
    ll total = half + half2;
    if (total <= x) {
      cout << 2*k - 1 << '\n';
      continue;
    }

    ll h = 1, t = 2*k-1;
    ll ans = 0;
    while (h<=t) {
      ll mid = (h + t) / 2;
      ll cur;
      if(k >= mid) cur = sum(1, mid);
      else cur = sum(1,k) + sum(1, k-1) - sum(1, 2*k-mid-1);
      if (cur >= x) {
	t = mid-1;
	ans = mid;
      } else {
	h = mid+1;
      }
    }
    cout << ans << '\n';
  }
}

int main() {
  init();
  solve();
  return 0;
}
