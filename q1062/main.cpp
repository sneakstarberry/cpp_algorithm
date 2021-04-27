#include <iostream>
#include <vector>
using namespace std;
int N, K, MAX_NUM = 0;
vector<string> WORDS;

void dfs(int letters, int count_ones, int alpha) {
  if (count_ones >= K) {
    int cnt = 0;
    for (int i = 0; i < WORDS.size(); i++) {
      int flag = 1;
      for (int j = 0; j < WORDS[i].size(); j++) {
        if ((letters & (1 << (WORDS[i][j] - 'a'))) == 0) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        cnt++;
      }
    }
    if (cnt > MAX_NUM) {
      MAX_NUM = cnt;
    }
    return;
  }

  for (int i = alpha; i < 26; i++) {
    if ((letters & (1 << i)) == 0) {
      letters |= (1 << i);
      dfs(letters, count_ones + 1, i);
      letters &= ~(1 << i);
    }
  }
}

int main() {
  cin >> N >> K;

  if (K < 5) {
    cout << 0;
    return 0;
  }

  for (int i = 0; i < N; i++) {
    string tmp;
    cin >> tmp;
    WORDS.push_back(tmp);
  }

  int letters = 1 << ('a' - 'a') | 1 << ('n' - 'a') | 1 << ('c' - 'a') |
                1 << ('t' - 'a') | 1 << ('i' - 'a');
  dfs(letters, 5, 0);
  cout << MAX_NUM;
  return 0;
}