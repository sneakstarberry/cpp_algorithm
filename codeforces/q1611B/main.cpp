#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n;
  cin >> n;

  while (n--) {
    int a, b;
    cin >> a >> b;
    int result = min((a+b)/4, min(a,b));

    cout << result << endl;
  }
  return 0;
}
    
