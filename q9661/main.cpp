#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long long N;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  N %= 5;
  if (N == 1 || N == 3 || N == 4) {
    cout << "SK";

  } else {
    cout << "CY";
  }
}