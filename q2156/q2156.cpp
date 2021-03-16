#include <algorithm>
#include <iostream>

using namespace std;
// dp[n] = dp[n-3] + array[n] + array[n-1];
// dp[n] = dp[n-2] + array[n];
int N, DP[10001], ARR[10001];

int main() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> ARR[i];
  }
  DP[1] = ARR[1];
  DP[2] = ARR[1] + ARR[2];

  for (int i = 3; i <= N; i++) {
    DP[i] = max(DP[i - 3] + ARR[i] + ARR[i - 1], DP[i - 2] + ARR[i]);
    DP[i] = max(DP[i], DP[i - 1]);
  }
  cout << DP[N];

  return 0;
}