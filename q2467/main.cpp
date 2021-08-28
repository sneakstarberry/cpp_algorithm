#include <iostream>
#include <vector>
#include <cstdlib>

#define INF 100001
using namespace std;

int N;
int ARR[INF];

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> ARR[i];
  }

  int left = 0, right= N-1;

  int res1= ARR[left];
  int res2 = ARR[right];
  int result = abs(res2 + res1);

  while(right > left) {
    int tmp = ARR[left] + ARR[right];

    if(result > abs(tmp)) {
      res1 = ARR[left];
      res2 = ARR[right];
      result = tmp;
    }

    if(tmp < 0) {
      left++;
    } else {
      right--;
    }

  }

  cout << res1 <<  ' ' << res2;


  return 0;
}
