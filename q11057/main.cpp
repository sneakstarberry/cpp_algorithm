#include <iostream>
#define INF 1001
#define Moduler 10007
using namespace std;

int N, DP[1001][10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < 10; i++) {
    DP[1][i] = 1;
  }

  for (int i = 2; i <= N; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k <= j; k++) {
        DP[i][j] = DP[i][j] + DP[i - 1][k];
        DP[i][j] = DP[i][j] % Moduler;
      }
    }
  }

  int answer = 0;
  for (int i = 0; i < 10; i++) {
    answer = answer + DP[N][i];
  }
  answer = answer % Moduler;

  cout << answer;

  return 0;
}
