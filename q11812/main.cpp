#include <cmath>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

typedef long long ll;

ll N, K, Q, NODE1, NODE2;

void search() {
  ll node1, node2;
  if (NODE1 >= NODE2) {
    node1 = NODE1;
    node2 = NODE2;
  } else {
    node1 = NODE2;
    node2 = NODE1;
  }
  ll cnt = 0;
  if (K == 1) {
    cout << node1 - node2 << endl;
    return;
  }

  while (node1 != node2) {
    long max_num = max(node1, node2);
    node2 = min(node1, node2);
    node1 = (max_num - 2) / K + 1;
    cnt++;
  }
  cout << cnt << endl;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> K >> Q;

  while (Q--) {
    cin >> NODE1 >> NODE2;
    search();
  }
}