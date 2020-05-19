#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  vector<int> a;
  int count = 0;
  
  cin >> n;
  int m = n-1;

  for(int i=0; i<n;i++){
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  while(m!=0){
    int check=1;
    int check2=0;

    for(int j=m-1; j>=0;j--){
      if(a[j] >= check){
        m=j;
        check2=1;
      }
      check++;
    }
    if(check2==0){
      cout << "-1" << endl;
      return 0;
    }
    count++;
  }

  cout << count << endl;

  return 0;
}