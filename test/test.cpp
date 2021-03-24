#include <iostream>
using namespace std;

int main() {

  int a[2];
  if (a[4]) {
    cout << a[4] << endl;
    cout << "can access" << endl;
  } else {
    cout << "can't access" << endl;
  }
}