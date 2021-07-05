#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string S;

vector<int> getPartialMatch(string &N) {
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

vector<int> kmpSearch(string &src, string &search) {
  int n = src.size(), m = search.size();
  vector<int> ret;
  vector<int> pi = getPartialMatch(search);
  int begin = 0, matched = 0;

  while (begin <= n - m) {
    if (matched < m && src[begin + matched] == search[matched]) {
      ++matched;

      if (matched == m) {
        ret.push_back(begin);
      }
    } else {
      if (matched == 0) {
        ++begin;
      } else {
        begin += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }

  return ret;
}

int main() {
  cin >> S;
  int result = 0;
  for (int i = 0; i < S.size(); i++) {
    string temp = S.substr(i, S.size());

    vector<int> pi = getPartialMatch(temp);

    sort(pi.begin(), pi.end(), greater<int>());
    result = max(result, pi[0]);
  }

  cout << result << endl;
  return 0;
}
