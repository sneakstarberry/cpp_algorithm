#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int T, N;
int ARR[101];

int main() {
  vector<int> vec;
  vector<int> vec2;
  cin >> T;
  for (int i = 0; i < T; i++) {
    memset(ARR, 0, sizeof(ARR));
    cin >> N;
    for (int j = 0; j < N; j++) {
      int temp;
      cin >> temp;
      if (!ARR[temp]) {
        ARR[temp] = 1;
        vec.push_back(temp);
      } else {
        vec2.push_back(temp);
      }
    }

    sort(vec.begin(), vec.end());
    sort(vec2.begin(), vec2.end());

    vec.insert(vec.end(), vec2.begin(), vec2.end());

    for (int j = 0; j < vec.size(); j++) {
      if (j != vec.size() - 1) {
        cout << vec[j] << ' ';
      } else {
        cout << vec[j] << endl;
      }
    }
    vec.clear();
    vec2.clear();
  }
}