#include <algorithm>
#include <cstring>
#include <iostream>

#define MAX 100000 + 1
#define INF (1 << 31) - 1
using namespace std;

int N, S, ARR[MAX];

int main() {
  cin >> N >> S;
  memset(ARR, 0, sizeof(ARR));

  for (int i = 0; i < N; i++) {
    cin >> ARR[i];
  }

  int low = 0, high = 0;
  int sum = ARR[0];
  int result = INF;

  while (low <= high && high < N) {
    if (sum < S) {
      sum += ARR[++high];
    } else if (sum == S) {
      result = min(result, high - low + 1);
      sum += ARR[++high];
    } else if (sum > S) {
      result = min(result, high - low + 1);
      sum -= ARR[low++];
    }
  }

  if (result == INF) {
    cout << 0;
  } else {
    cout << result;
  }
  return 0;
}