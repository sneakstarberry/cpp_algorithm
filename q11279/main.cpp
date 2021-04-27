#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x;
  map<int, int> m;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 0) {
      if (m.empty()) {
        cout << 0 << endl;
      } else {
        cout << -m.begin().operator*().first << endl;
        if (m.begin().operator*().second > 1) {
          m[m.begin().operator*().first]--;
        } else {
          m.erase(m.begin().operator*().first);
        }
      }
    } else {
      if (m[-x]) {
        m[-x]++;
      } else {
        m[-x] = 1;
      }
    }
  }

  return 0;
}