#include <iostream>
#include <string>
#include <vector>

using namespace std;
string T, P;

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
  getline(cin, T);
  getline(cin, P);

  vector<int> ret = kmpSearch(T, P);

  cout << ret.size() << '\n';
  for (int i = 0; i < ret.size(); i++) {
    cout << ret[i] + 1 << ' ';
  }

  return 0;
}