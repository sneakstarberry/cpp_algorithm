#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N;


int main() {
  cin >> N;
  vector<vector<int> > vec(N, vector<int>(N, 0)); 
  for (int i=0; i<N; i++) {
    for (int j=0; j<i+1; j++) {
      cin >> vec[i][j];
    }
  }

  for(int i=1;i<N;i++) {
    for(int j=0;j<i+1;j++) {
      if (j == 0) {
	vec[i][j] += vec[i-1][j];
      } else if (j == i) {
	vec[i][j] += vec[i-1][j-1];
      } else {
	vec[i][j] += max(vec[i-1][j-1], vec[i-1][j]);
      }
    }
  }
  int result = 0;
  for (int i=0; i<N; i++) {
    result = max(result, vec[N-1][i]);
  }

  cout << result;
  return 0;
}
