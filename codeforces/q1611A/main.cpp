#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<int> integers;
int main()
{
  string num;
  cin >> N;

  while(N--) {
    cin >> num;
    
    if ((num.back() - '0') % 2 == 0) {
      cout << 0 << endl;
      continue;
    } else if ((num[0] - '0') % 2 == 0) {
      cout << 1 << endl;
      continue;
    } else {
      bool flag = false;
      for(int i=0;i<num.length();i++) {
	if ((num[i] - '0') % 2 == 0) {
	  cout << 2 << endl;
	  flag = true;
	  break;
	}
      }
      if(!flag) {
	cout << "-1" << endl;
      }
    }
    
  }
  

  return 0;
}
