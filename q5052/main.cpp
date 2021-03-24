#include <iostream>
#include <unordered_map>
#include <vector>

#define endl '\n'

using namespace std;

int N;
vector<string> PHONE_BOOK;
unordered_map<string, int> IS_PHONE_NUMBER;

void solve();
void init();

int main() {
  int t;
  cin >> t;

  while (t--) {
    init();
    solve();
    PHONE_BOOK.clear();
    IS_PHONE_NUMBER.clear();
  }
}

void init() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    string tmp;
    cin >> tmp;
    PHONE_BOOK.push_back(tmp);
  }
}

void solve() {
  for (int i = 0; i < N; i++) {
    IS_PHONE_NUMBER[PHONE_BOOK[i]] = 1;
  }
  for (int i = 0; i < N; i++) {
    string phone_number = "";
    for (int j = 0; j < PHONE_BOOK[i].length(); j++) {
      phone_number.push_back(PHONE_BOOK[i][j]);
      if (IS_PHONE_NUMBER[phone_number] && PHONE_BOOK[i] != phone_number) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
  return;
}
