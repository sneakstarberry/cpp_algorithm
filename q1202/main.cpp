#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 300000 + 1

using namespace std;

int N, K, bags[MAX];
pair<int, int> jewelries[MAX];

int main() {
  priority_queue<int> pq;
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    cin >> jewelries[i].first >> jewelries[i].second;
  }
  for (int i = 0; i < K; i++) {
    cin >> bags[i];
  }

  sort(bags, bags + K);
  sort(jewelries, jewelries + N);

  long long result = 0;
  int idx = 0;

  for (int i = 0; i < K; i++) {
    while (idx < N && jewelries[idx].first <= bags[i]) {
      pq.push(jewelries[idx++].second);
    }

    if (!pq.empty()) {
      result += pq.top();
      pq.pop();
    }
  }

  cout << result << '\n';

  return 0;
}