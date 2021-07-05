#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll N, M, K, A, B, C;

ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end) {
  if (start == end) {
    return tree[node] = arr[start];
  } else {
    return tree[node] =
               init(arr, tree, node * 2, start, (start + end) / 2) +
               init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
  }
}

ll sum(vector<ll> &tree, int node, int start, int end, int left, int right) {
  if (left > end || right < start) {
    return 0;
  }
  if (left <= start && end <= right) {
    return tree[node];
  }
  return sum(tree, node * 2, start, (start + end) / 2, left, right) +
         sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<ll> &tree, int node, int start, int end, int index,
            ll diff) {
  if (index < start || index > end)
    return;
  tree[node] = tree[node] + diff;
  if (start != end) {
    update(tree, node * 2, start, (start + end) / 2, index, diff);
    update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
  }
}

int main() {
  cin >> N >> M >> K;
  vector<ll> arr(N);
  int h = (int)ceil(log2(N));
  int tree_size = 1 << (h + 1);
  vector<ll> tree(tree_size);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  init(arr, tree, 1, 0, N - 1);

  for (int i = 0; i < M + K; i++) {
    cin >> A >> B >> C;
    if (A == 1) {
      B -= 1;
      ll diff = C - arr[B];
      arr[B] = C;
      update(tree, 1, 0, N - 1, B, diff);
    } else if (A == 2) {
      cout << sum(tree, 1, 0, N - 1, B - 1, C - 1) << '\n';
    }
  }
  return 0;
}