#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> test(0,4);

  for (int i : test) {
    cout << i << endl;
  }

  return 0;
}
