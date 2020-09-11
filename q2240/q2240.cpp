#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, W, ans=0;
    int arr[1001];
    int dp[3][1001][32];
    cin >> T >> W;
    for(int i=1; i<=T; i++){
        cin >> arr[i];
    }

    for (int i = 1; i <= T; i++) {
      for (int j = 1; j <= W + 1; j++) {
        if (arr[i] == 1) {
          dp[1][i][j] = max(dp[1][i - 1][j] + 1, dp[2][i - 1][j - 1] + 1);
          dp[2][i][j] = max(dp[1][i - 1][j - 1], dp[2][i - 1][j]);
        } else {
          if (i == 1 && j == 1) {
            continue;
          }
          dp[1][i][j] = max(dp[2][i - 1][j - 1], dp[1][i - 1][j]);
          dp[2][i][j] = max(dp[1][i - 1][j - 1] + 1, dp[2][i - 1][j] + 1);
        }
      }
    }
    for (int i = 1; i <= W + 1; i++) {
      ans = max(ans, max(dp[1][T][i], dp[2][T][i]));
    }

    cout << ans;
    return 0;
}