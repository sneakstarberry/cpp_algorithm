#include <iostream>
#include <string>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n, m;
  int memory = (1<<31) - 1;
  int arr[10001] = {0,};
  cin >> n >> m;

  for (int i=0; i<n; i++) {
    string word;
    cin >> word;
    for(int j=0; j<word.length();j++) {
      int cur = word[j]-'a';
      arr[i] |= 1 << cur;
    }
  }

  for (int i=0; i<m; i++) {
    int state;
    char alphabet;
    cin >> state >> alphabet;

    memory ^= (1 << (alphabet - 'a'));
    
    int cnt = 0;

    for (int j=0; j<n; j++) {
      if((arr[j] & memory) == arr[j]) {
	cnt++;
      }
    }
    cout << cnt << '\n';
  }
    
  return 0;
}
