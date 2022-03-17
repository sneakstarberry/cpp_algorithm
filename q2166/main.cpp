#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double vector_outline(double x1, double x2, double x3, double y1, double y2, double y3) {
	double res = x1 * y2 + x2 * y3 + x3 * y1;
	res += (-y1 * x2 - y2 * x3 - y3 * x1);
	return res / 2;
}

int main()
{
  int n;
  cin >> n;
  vector<pair<double, double> > vec(n);

  for (int i = 0; i<n; ++i) {
    cin >> vec[i].first >> vec[i].second;
  }

  double res = 0;

  for (int i = 1; i<n; i++) {
    res += vector_outline(vec[0].first, vec[i-1].first, vec[i].first, vec[0].second, vec[i-1].second, vec[i].second);
  }

  cout << fixed;
  cout.precision(1);

  cout << abs(res);

  return 0;
}
