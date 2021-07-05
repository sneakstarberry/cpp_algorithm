#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

#define INF (1LL << 63) - 1

ll N, M;
ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end) {
  if (start == end) {
    return tree[node] = arr[start];
  } else {
    return tree[node] =
               min(init(arr, tree, node * 2, start, (start + end) / 2),
                   init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end));
  }
}

ll range_min(vector<ll> &arr, vector<ll> &tree, int node, int start, int end,
             int left, int right) {
  if (left > end || right < start) {
    return INF;
  }
  if (left <= start && end <= right) {
    return tree[node];
  }
  return min(
      range_min(arr, tree, node * 2, start, (start + end) / 2, left, right),
      range_min(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end, left,
                right));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  int h = (int)ceil(log2(N));
  vector<ll> arr(N);
  vector<ll> tree(1 << (h + 1));

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  init(arr, tree, 1, 0, N - 1);

  while (M--) {
    int left, right;
    cin >> left >> right;
    cout << range_min(arr, tree, 1, 0, N - 1, left - 1, right - 1) << '\n';
  }
  return 0;
}