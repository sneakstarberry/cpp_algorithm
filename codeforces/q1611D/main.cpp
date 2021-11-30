#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
int T, N;
int main()
{
  cin >> T;

  while(T--) {
    cin >> N;
    vector<int> b(N+1), p(N+1), dp(N+1, -1);
    for (int i=1; i<=N; i++) {
      cin >> b[i];
    }
    for (int i=1; i<=N; i++) {
      cin >> p[i];
    }

    if (b[p[1]] != p[1]) {
      cout << "-1" << endl;
      continue;
    }

    bool flag = false;
    dp[p[1]] = 0;

    for (int i = 2; i<=N; i++) {
      if (dp[b[p[i]]] == -1) {
	cout << "-1" << endl;
	flag = true;
	break;
      } else {
	dp[p[i]] = dp[p[i-1]] + 1;
      }
    }

    if (!flag) {
      for (int i=1; i<=N; i++) {
        cout << dp[i] - dp[b[i]] << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
