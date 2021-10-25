#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct ALPHA {
  int digit;
  char al;
  ALPHA(int digit, char al) : digit(digit), al(al) {}
  bool operator<(const ALPHA &b) const { return digit > b.digit; }
};

unordered_map<char, int> CNT;
map<int, vector<char> > AL;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  vector<string> words;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    words.push_back(tmp);
  }

  for (int i = 0; i < (int)words.size(); i++) {
    for (int j = 0; j < (int)words[i].length(); j++) {
      int digit = words[i].length() - j;
      char al = words[i][j];

      if (!CNT[al])
        CNT[al] = pow(10, digit);

      else
        CNT[al] += pow(10, digit);
    }
  }

  for (auto al : CNT) {
    AL[-al.second].push_back(al.first);
  }

  int num = 9;

  for (auto al : AL) {
    for(int i=0;i<al.second.size();i++) {
      CNT[al.second[i]] = num--;
    }
  }

  num = 0;

  for (int i = 0; i < words.size(); i++) {
    int tmp = 0;
    for (int j = 0; j < words[i].length(); j++) {
      char al = words[i][j];
      tmp += CNT[al];
      tmp *= 10;
    }
    tmp /= 10;
    num += tmp;
  }

  cout << num << endl;

  return 0;
}
