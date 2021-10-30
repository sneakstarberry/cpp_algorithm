#include <iostream>

using namespace std;

int main() {
  int t, n, m;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;

  while (t--) {
    cin >> n >> m;
    for (int i =0; i<m; ++i) {
      int a, b;
      cin >> a >> b;
    }

    cout << n - 1 << '\n';
  }

  return 0;
}
