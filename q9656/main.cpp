#include <iostream>

using namespace std;

int N;

int main() {
  cin >> N;

  if (N % 2) {
    cout << "CY";
  } else {
    cout << "SK";
  }
  return 0;
}