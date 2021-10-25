#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int CNT = 0, L, W, H, N;
bool flag = false;
int cube[20];
void dc(int l, int w, int h, int m) {
  if (l == 0 || w == 0 || h == 0) return;
  for(int i=m; i >= 0; i--) {
    if(cube[i] == 0) {
      continue;
    }
    int len = pow(2, i);
    if( len <= l && len <= w && len <= h ) {
      cube[i]--;
      CNT++;
      dc(len, len, h-len, i);
      dc(l-len, len, h, i);
      dc(l, w- len, h, i);
      return;
    }
  }
  flag = 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> L >> W >> H >> N;
  int a= 0,b = 0;
  int m = 0;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    if(a > m) m = a;
    cube[a] = b;
  }
  dc(L, W, H, m);
  if(flag) cout << -1 << endl;
  else cout << CNT << endl;
  return 0;
}
