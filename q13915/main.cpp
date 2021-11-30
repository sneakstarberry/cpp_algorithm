#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int arr[1001] = {0,};
int main()
{
  int n;
  while (cin >> n) {
    memset(arr, 0, sizeof(arr));
    for (int i=0; i<n; i++) {
      string tmp;
      cin >> tmp;
      for (int j=0; j<tmp.size(); j++) {
	arr[i] |= 1 << (tmp[j] - '1');
      }
    }

    vector<int> exp;
    exp.push_back(arr[0]);
    for (int i=0; i<n; i++) {
      bool flag = true;
      for (int j=0; j<exp.size(); j++) {
        if(arr[i] == exp[j]) flag = false;
      }
      if (flag) {
	exp.push_back(arr[i]);
      }
    }

    cout << exp.size() << '\n';
  }

  return 0;
}
