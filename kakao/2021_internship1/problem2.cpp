#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int is_visited[5][5] = {
    0,
};
int MIN_NUM = 2000;

vector<int> solution(vector<vector<string>> places) {
  vector<int> answer;
  for (int i = 0; i < 5; i++) {
    MIN_NUM = 2000;
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        queue<pair<pair<int, int>, int>> q;
        if (places[i][j][k] == 'P') {
          q.push({{j, k}, 0});
          memset(is_visited, 0, sizeof(is_visited));
          is_visited[j][k] = 1;
        }

        while (!q.empty()) {
          int flag = 0;
          int y = q.front().first.first;
          int x = q.front().first.second;
          int distance = q.front().second;

          q.pop();

          for (int l = 0; l < 4; l++) {
            int n_x = x + dx[l];
            int n_y = y + dy[l];

            if (n_x < 0 || n_x > 4 || n_y < 0 || n_y > 4)
              continue;
            if (is_visited[n_y][n_x] || places[i][n_y][n_x] == 'X')
              continue;
            if (places[i][n_y][n_x] == 'P' && MIN_NUM > distance + 1) {
              MIN_NUM = distance + 1;
            }
            is_visited[n_y][n_x] = 1;

            q.push({{n_y, n_x}, distance + 1});
          }
        }
      }
    }
    if (MIN_NUM <= 2) {
      answer.push_back(0);
    } else {
      answer.push_back(1);
    }
  }
  return answer;
}

int main() {
  vector<vector<string>> places = {
      {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
      {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
      {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"},
      {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
      {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};

  vector<int> answer = solution(places);
  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i] << endl;
  }
}