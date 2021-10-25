#include <iostream>

using namespace std;

int main()
{
  int K, a;
  
  int arr[10] = {0,};

  cin >> K;

  for (int i=0; i<6; i++) {
    cin >> a;
    cin >> arr[i];
  }
  int max_h = 0, max_w = 0;
  for (int i=0; i<6; i++) {
    if (i%2 == 0) {
      if (max_w < arr[i]) {
	max_w = arr[i];
      }
    } else {
      if (max_h < arr[i]) {
	max_h = arr[i];
      }
    }
  }
  int w = 0, h = 0;
  for (int i=0; i<6; i++) {
    if (i%2 == 0) {
      if (max_h == arr[(i+5)%6] + arr[(i+1)%6]) {
	w = arr[i];
      }
    } else {
      if (max_w == arr[(i+5)%6] + arr[(i+1)%6]) {
	h = arr[i];
      }
    }
  }

  cout << ((max_h * max_w - h*w)*K) << endl;

  return 0;
}
