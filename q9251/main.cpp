#include <iostream>
#include <cmath>
using namespace std;
int DP[1001][1001];
int main()
{
  string a_string, b_string;

  cin >> a_string >> b_string;

  for (int i=1; i<=a_string.size(); i++) {
    for (int j=1; j<=b_string.size(); j++) {
      if(a_string[i-1] == b_string[j-1]) {
	DP[i][j] = DP[i-1][j-1] +1;
      } else {
	DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
      }
    }
  }

  cout << DP[a_string.size()][b_string.size()];
  return 0;
}
