#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  priority_queue<int> q;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (tmp == 0) {
      if (q.empty()) {
        cout << 0 << endl;
      } else {
        cout << -q.top() << endl;
        q.pop();
      }
    } else {
      q.push(-tmp);
    }
  }

  return 0;
}