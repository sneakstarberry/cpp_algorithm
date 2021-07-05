#include <cmath>
#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

typedef long long ll;

ll N, M, K, A, B, C;

ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end) {
  if (start == end) {
    return tree[node] = arr[start];
  } else {
    return tree[node] =
               ((init(arr, tree, node * 2, start, (start + end) / 2) % MOD) *
                (init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end) %
                 MOD)) %
               MOD;
  }
}

ll update(vector<ll> &tree, int node, int start, int end, int index, ll val) {
  if (index < start || index > end)
    return tree[node];
  if (start == end) {
    return tree[node] = val;
  }
  return tree[node] =
             (update(tree, node * 2, start, (start + end) / 2, index, val) *
              update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index,
                     val)) %
             MOD;
}

ll mul(vector<ll> &tree, int node, int start, int end, int left, int right) {
  if (left > end || right < start) {
    return 1;
  }
  if (left <= start && end <= right) {
    return tree[node];
  }
  return (mul(tree, node * 2, start, (start + end) / 2, left, right) *
          mul(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right)) %
         MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> K;
  int h = (int)ceil(log2(N));
  int tree_size = 1 << (h + 1);
  vector<ll> arr(N);
  vector<ll> tree(tree_size);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  init(arr, tree, 1, 0, N - 1);
  M += K;
  while (M--) {
    cin >> A >> B >> C;
    if (A == 1) {
      update(tree, 1, 0, N - 1, B - 1, C);
    } else if (A == 2) {
      cout << mul(tree, 1, 0, N - 1, B - 1, C - 1) % MOD << '\n';
    }
  }
  return 0;
}