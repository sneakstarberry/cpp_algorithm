
#include <iostream>

using namespace std;

int main()
{
  int n;
  char c;
  int num;
  cin >> n;
  pair<int, int> point = make_pair(0, 0);
  for (int i=0; i<n; i++) {
    cin >> c >> num;
    int x = point.first;
    int y = point.second;
    if(c == 'u') {
      y += num;
    } else if (c == 'd') {
      y -= num;
    } else if (c == 'l') {
      x -= num;
    } else if (c == 'r') {
      x += num;
    }
    point = make_pair(x, y);
  }

  cout << point.first << ' ' << point.second;

  return 0;
}
