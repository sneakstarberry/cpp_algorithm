#include <cmath>
#include <iostream>

using namespace std;

double X, Y, C;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin.precision(7);
  cin >> X >> Y >> C;
  double answer;
  double h, l, m;
  h = min(X, Y);
  l = 0;
  m = (h + l) / 2;
  while (l - h < 0.00001) {
    m = (h + l) / 2;

    double high1 = pow(X, 2) - pow(m, 2);
    double high2 = pow(Y, 2) - pow(m, 2);

    double assume_c = (sqrt(high1) * sqrt(high2)) / (sqrt(high1) + sqrt(high2));

    if (assume_c <= C) {
      answer = m;
      h = m;
    } else {
      l = m;
    }
  }
  cout << fixed;
  cout.precision(3);
  cout << answer;
}