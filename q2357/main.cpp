#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define INF (1 << 31) - 1

int N, M;
int arr[100001];
vector<int> tree_min, tree_max;

void init_min( int node, int start, int end) {
  if (start == end) {
    tree_min[node] = arr[start];
    return;
  } else {
    init_min( node*2, start, (start+end)/2);
    init_min( node*2 + 1, (start+end)/2+1, end);
    tree_min[node] = min(tree_min[node*2], tree_min[node*2 + 1]);
    return;
  }
}

void init_max( int node, int start, int end) {
  if (start == end) {
    tree_max[node] = arr[start];
    return;
  } else {
    init_max( node*2, start, (start+end)/2);
    init_max( node*2 + 1, (start+end)/2+1, end);
    tree_max[node] = max(tree_max[node*2], tree_max[node*2 + 1]);
    return;
  }
}

int range_min(int node, int start, int end, int left, int right) {
  if(left > end || right < start) return INF;
  if(left <= start && right >= end) return tree_min[node];

  return min(
	     range_min( node*2, start, (start+end)/2, left, right),
	     range_min( node*2 + 1, (start+end)/2+1, end, left, right));
}
int range_max(int node, int start, int end, int left, int right) {
  if(left > end || right < start) return 0;
  if(left <= start && right >= end) return tree_max[node];

  return max(
	     range_max( node*2, start, (start+end)/2, left, right),
	     range_max( node*2 + 1, (start+end)/2+1, end, left, right));
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  int size = 1 << int(ceil(log2(N))+1);
  tree_min.resize(size);
  tree_max.resize(size);
 
  for (int i=0; i<N; i++) {
    cin >>arr[i];
  }

  init_min( 1, 0, N-1);
  init_max( 1, 0, N-1);

  while(M--) {
    int left, right;
    cin >> left >> right;
    cout << range_min(1, 0, N-1, left-1, right-1) << ' ' << range_max(1, 0, N-1, left-1, right-1) << '\n';
  }
  return 0;
}
