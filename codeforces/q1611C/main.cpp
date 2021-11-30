#include <deque>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;

    vector<int> v(n);

    for (int i=0; i<n;i++) {
      cin >> v[i];
    }

    reverse(v.begin(), v.end());

    if (v[0] == n || v[n-1] == n) {
      cout << n << ' ';

      for (int i=0; i<n; i++) {
        if (v[i] == n) {
	  continue;
	}
	cout << v[i] << ' ' ;
      }
      cout << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
