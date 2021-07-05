#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

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

int T;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;

  while (T--) {
    string a, w, s;
    cin >> a >> w >> s;

    int n = a.length();
    vector<int> result;
    map<char, int> m;
    map<int, char> rm;

    for (int i = 0; i < n; i++) {
      m[a[i]] = i;
      rm[i] = a[i];
    }

    for (int i = 0; i < n; i++) {
      if (i) {
        for (int j = 0; j < w.length(); j++) {
          w[j] = rm[(m[w[j]] + 1) % n];
        }
      }
      if (kmpSearch(s, w).size() == 1) {
        result.push_back(i);
      }
    }
    if (!result.size()) {
      cout << "no solution\n";
    } else if (result.size() == 1) {
      cout << "unique: " << result[0] << '\n';
    } else {
      cout << "ambiguous: ";
      for (auto x : result) {
        cout << x << ' ';
      }
      cout << '\n';
    }
  }

  return 0;
}