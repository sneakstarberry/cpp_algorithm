#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long k, n;
  vector<long long> vec;

  cin >> k >> n;

  for (int i = 0; i < k; i++) {
    long long tmp;
    cin >> tmp;
    vec.push_back(tmp);
  }
  sort(vec.begin(), vec.end());
  long long left, right, mid, cnt = 0, max_length = 0;
  left = 0;

  right = vec.back() + 1;
  mid = (right + left) / 2;

  while (left + 1 < right) {
    cnt = 0;
    mid = (right + left) / 2;

    for (long long i = 0; i < vec.size(); i++) {
      cnt += vec[i] / mid;
    }

    if (n <= cnt) {
      if (mid > max_length) {
        max_length = mid;
      }
      left = mid;
    } else {
      right = mid;
    }
  }
  std::cout << max_length;
}