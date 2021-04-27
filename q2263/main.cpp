#include <iostream>
#define MAX 100001
using namespace std;

int N, IN[MAX], POST[MAX], IDX[MAX];

void pre(int in_start, int in_end, int post_start, int post_end);

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> IN[i];
    IDX[IN[i]] = i;
  }

  for (int i = 0; i < N; i++) {
    cin >> POST[i];
  }

  pre(0, N - 1, 0, N - 1);
  return 0;
}

void pre(int in_start, int in_end, int post_start, int post_end) {
  if (in_start > in_end || post_start > post_end)
    return;

  int root = POST[post_end];
  cout << root << ' ';

  pre(in_start, IDX[root] - 1, post_start,
      post_start + (IDX[root] - in_start) - 1);
  pre(IDX[root] + 1, in_end, post_start + (IDX[root] - in_start), post_end - 1);
}
