#include <cstring>
#include <iostream>

using namespace std;

int T, N;
int DP[101];

int main() {
  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> N;
    int cnt = 0;
    memset(DP, 0, sizeof(DP));
    for (int j = 1; j <= N; j++) {
      for (int k = 1; j * k <= N; k++) {
        if (DP[j * k] == 0) {
          DP[j * k] = 1;
        } else {
          DP[j * k] = 0;
        }
      }
    }
    for (int j = 1; j <= N; j++) {
      cnt += DP[j];
    }
    cout << cnt << endl;
  }

  return 0;
}