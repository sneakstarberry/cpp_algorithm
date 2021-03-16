#include <iostream>
#include <list>
using namespace std;

int N, K;
int CNT;
int main() {

  cin >> N >> K;
  list<int> lt;

  for (int i = 1; i <= N; i++) {
    lt.push_back(i);
  }

  auto cursor = lt.begin();

  cout << "<";
  while (N--) {
    cursor--;
    for (int i = 0; i < K; i++) {
      cursor++;
      if (cursor == lt.end()) {
        cursor = lt.begin();
      }
    }
    if (lt.size() == 1) {
      cout << *cursor;
      break;
    }
    cout << *cursor << ", ";
    cursor = lt.erase(cursor);
  }
  cout << ">";
}