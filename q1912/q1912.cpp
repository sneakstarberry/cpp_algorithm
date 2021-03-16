#include <iostream>
#include <vector>

using namespace std;

int N, dp[100001];

int main() {
  cin >> N;
  int max;

  for (int i = 1; i <= N; i++) {
    cin >> dp[i];
  }

  max = dp[1];

  for (int i = 2; i <= N; i++) {
    if (dp[i - 1] > 0 && dp[i] + dp[i - 1] > 0) {
      dp[i] += dp[i - 1];
    }

    if (max < dp[i]) {
      max = dp[i];
    }
  }
  cout << max;
  return 0;
}