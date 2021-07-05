#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string S, K;
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
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string without_number = "";
  cin >> S;
  cin >> K;

  for (int i = 0; i < S.length(); i++) {
    if ('0' <= S[i] && S[i] <= '9')
      continue;

    without_number.push_back(S[i]);
  }

  vector<int> result = kmpSearch(without_number, K);

  if (result.size() > 0) {
    cout << '1';
  } else {
    cout << '0';
  }

  return 0;
}