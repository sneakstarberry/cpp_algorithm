#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPartialMatch(vector<int> &N) {
  int M = N.size();
  vector<int> pi(M, 0);
  int begin = 1, matched = 0;

  while (begin + matched < M) {
    if (N[begin + matched] == N[matched]) {
      matched++;
      pi[begin + matched - 1] = matched;
    } else {
      if (matched == 0) {
        begin++;
      } else {
        begin += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }

  return pi;
}

int N;
string S;

int main() {
  cin >> N;
  int result = 0, cnt = 0;
  vector<int> vec(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> vec[i];
  }

  reverse(vec.begin(), vec.end());

  vector<int> pi = getPartialMatch(vec);

  sort(pi.begin(), pi.end(), greater<int>());

  for (int i = 0; i < pi.size(); i++) {
    if (pi[0] == pi[i]) {
      cnt++;
    }
  }

  if (pi[0] == 0) {
    cout << -1;
  } else {
    cout << pi[0] << ' ' << cnt;
  }

  return 0;
}