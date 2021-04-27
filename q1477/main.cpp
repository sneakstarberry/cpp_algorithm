#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, L;

int main() {
  cin >> N >> M >> L;
  int answer;
  vector<int> hugaeso_group;

  for (int i = 0; i < N; i++) {
    int hugaeso;
    cin >> hugaeso;
    hugaeso_group.push_back(hugaeso);
  }
  sort(hugaeso_group.begin(), hugaeso_group.end());

  int m, h, l;

  l = 0;
  h = L;
  m = (l + h) / 2;

  while (l + 1 < h) {
    m = (l + h) / 2;
    int cnt = 0, prev_hugaeso = 0;

    for (int i = 0; i < N; i++) {
      cnt += (hugaeso_group[i] - prev_hugaeso) % m == 0
                 ? (hugaeso_group[i] - prev_hugaeso) / m - 1
                 : (hugaeso_group[i] - prev_hugaeso) / m;
      prev_hugaeso = hugaeso_group[i];
    }

    cnt += (L - hugaeso_group[N - 1]) % m == 0
               ? (L - hugaeso_group[N - 1]) / m - 1
               : (L - hugaeso_group[N - 1]) / m;

    if (cnt <= M) {
      answer = m;
      h = m;
    } else {
      l = m;
    }
  }
  cout << answer;
}