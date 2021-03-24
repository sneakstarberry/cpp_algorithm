#include <algorithm>
#include <iostream>

using namespace std;
#define MAX 200111

int N, C;

void solve();
int needed_wifi_counter(int distance, int house_x_group[MAX]);

int main() {
  cin >> N >> C;

  solve();

  return 0;
}

void solve() {
  int house_x_group[MAX];

  for (int i = 0; i < N; i++) {
    cin >> house_x_group[i];
  }
  sort(house_x_group, house_x_group + N);
  int h, l, m, needed_wifi_cnt, ans = 1;
  h = house_x_group[N - 1] + 1;
  l = 0;

  while (l + 1 < h) {
    m = (h + l) / 2;

    needed_wifi_cnt = needed_wifi_counter(m, house_x_group);

    if (needed_wifi_cnt < C) {
      h = m;
    } else {
      ans = m;
      l = m;
    }
  }
  cout << ans;
}

int needed_wifi_counter(int distance, int house_x_group[MAX]) {
  int cnt = 1;
  int prev = house_x_group[0];
  for (int i = 1; i < N; i++) {
    if (house_x_group[i] - prev >= distance) {
      cnt++;
      prev = house_x_group[i];
    }
  }

  return cnt;
}