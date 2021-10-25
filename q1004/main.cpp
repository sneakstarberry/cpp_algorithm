#include <iostream>
#include <cmath>
using namespace std;


int T, N;
pair<int, int> S, A;

bool is_in(int cx, int cy, int r, pair<int, int> compare) {
  int x = cx - compare.first;
  int y = cy - compare.second;
  int d = pow(x, 2) + pow(y, 2);

  if (d <= r*r) {
    return true;
  } else {
    return false;
  } 
}

int main()
{
  cin >> T;

  while (T--) {
    cin >> S.first >> S.second >> A.first >> A.second;

    cin >> N;
    int rst = 0;
    for (int i=0; i<N; i++) {
      bool a_flag = false, s_flag = false;
      int cx , cy, r;
      cin >> cx >> cy >> r;

      s_flag = is_in(cx, cy, r, S);
      a_flag = is_in(cx, cy, r, A);

      if (s_flag == a_flag) {
        continue;
      } else if (s_flag != a_flag) {
	rst++;
      }
    }
    cout << rst << '\n';
  }

  
  return 0;
}
