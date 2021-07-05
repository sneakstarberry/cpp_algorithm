#include <iostream>

using namespace std;

int N;

int main() {
  cin >> N;

  if (N % 2) {
    cout << "SK";
  } else {
    cout << "CY";
  }
  return 0;
}