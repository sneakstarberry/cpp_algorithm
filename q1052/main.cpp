#include <iostream>

using namespace std;

int add_water(int x) {
  int cnt = 0;
  while (x) {
    if (x % 2 == 1) {
      cnt++;
    }
    x /= 2;
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  int answer = 0;

  cin >> N >> K;

  if (N <= K) {
    cout << 0 << '\n';
    return 0;
  }

  while (1) {
    int tmp = add_water(N);
    if (tmp <= K)
      break;

    answer++;
    N++;
  }

  cout << answer;
  return 0;
}