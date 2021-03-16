#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define endl '\n'

using namespace std;

int main() {
  int n, num = 1, max;
  string best;
  string arr[1001];
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr+n);

  string temp = arr[0];

  for (int i = 1; i < n; i++) {
    if (temp == arr[i]) {
      num++;
      if (num > max) {
        max = num;
        best = temp;
      }
    } else {
      num = 1;
      temp = arr[i];
    }
  }

  cout << best;
  
  return 0;
}
