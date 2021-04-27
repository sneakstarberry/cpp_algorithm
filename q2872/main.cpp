#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, input, max_num, cnt;
  max_num = 1;
  cin >> n;
  cnt = n - 1;
  for (int i = 0; i < n; i++) {
    cin >> input;

    if (input > max_num) {
      if (max_num + 1 == input) {
        cnt--;
      } else if (max_num + 1 < input) {
        cnt = n - 1;
      }

      max_num = input;
    }
  }

  cout << cnt;
}