#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define MAX 10011

using namespace std;

int N, M, CNT;
vector<int> MOST_HACK_COMPUTER, computer_hack[MAX];
int is_visited[MAX];

void dfs(int current_computer);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int max = -1;
  cin >> N >> M;
  int tmp[2];
  for (int i = 0; i < M; i++) {
    cin >> tmp[0] >> tmp[1];
    computer_hack[tmp[1]].push_back(tmp[0]);
  }

  for (int i = 1; i <= N; i++) {
    memset(is_visited, 0, sizeof(is_visited));
    CNT = 0;
    dfs(i);
    if (max < CNT) {
      max = CNT;
      MOST_HACK_COMPUTER.clear();
      MOST_HACK_COMPUTER.push_back(i);
    } else if (max == CNT) {
      MOST_HACK_COMPUTER.push_back(i);
    }
  }

  for (int i = 0; i < MOST_HACK_COMPUTER.size(); i++) {
    cout << MOST_HACK_COMPUTER[i] << ' ';
  }
  return 0;
}

void dfs(int current_computer) {
  is_visited[current_computer] = 1;
  CNT++;
  for (int i = 0; i < computer_hack[current_computer].size(); i++) {
    int next_computer = computer_hack[current_computer][i];
    if (!is_visited[next_computer]) {
      dfs(next_computer);
    }
  }
}
