#include <iostream>
#include <vector>
using namespace std;
struct Test {
  int n,m; vector<vector<int>>v;
  Test(int n, int m) : n(n), m(m), v(n, vector<int>(m)) {}

	vector<int>& operator[] (int i) { return v[i]; }
};
int main() {
  Test test(3,3);
  for(int i=0; i<3;i++ ) {
    for(int j=0;j<3;j++) {
      cout << test[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}