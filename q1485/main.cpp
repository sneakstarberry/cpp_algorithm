#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int tri(pair<int, int> point_a, pair<int, int> point_b) {
  int w = point_a.first - point_b.first;
  int h = point_a.second - point_b.second;
  
  return pow(w,2) + pow(h,2);
};

int main()
{
  int t;
  cin >> t;

  while (t--) {
    pair<int, int> points[4] = {make_pair(0,0),};
    int arr[3] = {0,};
    for (int i=0; i<4; i++) {
      cin >> points[i].first >> points[i].second;
    }

    arr[0] = tri(points[0], points[3]);
    arr[1] = tri(points[1], points[3]);
    arr[2] = tri(points[2], points[3]);

    if (arr[0] == arr[1]) {
      if(arr[0] + arr[1] == arr[2]) {
	cout << 1 << endl;
	break;
      }
    }
    if(arr[1] == arr[2]) {
      if (arr[1] + arr[2] == arr[0]) {
	cout << 1 << endl;
	break;
      }
    }
    if (arr[0] == arr[2]) {
      if (arr[0] + arr[2] == arr[1]) {
        cout << 1 << endl;
	break;
      }
    }
    
    cout << 0 << endl;
    
  }
  return 0;
}
