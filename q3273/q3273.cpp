#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, TARGET, ANS = 0;

vector<int> vec;

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    vec.push_back(tmp);
  }

  cin >> TARGET;

  sort(vec.begin(), vec.end());
  auto cursor_s = vec.begin();
  auto cursor_e = vec.end();
  cursor_e--;

  while (1) {
    if (cursor_s >= cursor_e) {
      break;
    }

    if (*cursor_s + *cursor_e > TARGET) {
      cursor_e--;
    } else if (*cursor_s + *cursor_e < TARGET) {
      cursor_s++;
    } else if (*cursor_s + *cursor_e == TARGET) {
      ANS++;
      cursor_s++;
      cursor_e--;
    }
  }
  cout << ANS;
  return 0;
}