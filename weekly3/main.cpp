#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Piece {
  int x, y;
  vector<vector<int>> map;
  int cnt;

  vector<vector<int>> rotate() {
    int tmpy = x;
    int tmpx = y;
    int tmpmap[6][6] = {
        0,
    };
    for (int i = 0; i < y; i++) {
      for (int j = 0; j < x; j++) {
        tmpmap[j][y - 1 - i] = map[i][j];
      }
    }

    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        map[i][j] = tmpmap[i][j];
      }
    }

    y = tmpy;
    x = tmpx;

    return map;
  }
};

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
vector<Piece> game_board_piece;

void bfs(pair<int, int> start, vector<vector<int>> &board) {
  int map[12][12] = {
      0,
  };
  int size = board.size();
  int cnt = 1;
  pair<int, int> lu = make_pair(0, 5), rd = make_pair(0, 5);
  queue<pair<int, int>> q;
  q.push(start);

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    if (lu.second > x - start.second + 5) {
      lu.second = x - start.second + 5;
    }

    if (rd.first < y - start.first) {
      rd.first = y - start.first;
    }

    if (rd.second < x - start.second + 5) {
      rd.second = x - start.second + 5;
    }
    board[y][x] = 1;
    map[y - start.first][x - start.second + 5] = 1;
    for (int i = 0; i < 4; i++) {
      int n_y = y + dy[i];
      int n_x = x + dx[i];

      if (0 <= n_x && 0 <= n_y && n_x < size && n_y < size &&
          board[n_y][n_x] == 0) {
        cnt++;
        q.push(make_pair(n_y, n_x));
      }
    }
  }
  vector<vector<int>> piece(6, vector<int>(6, 0));
  for (int i = 0; i < rd.first + 1; i++) {
    for (int j = lu.second; j < rd.second + 1; j++) {
      int n_j = j - lu.second;
      piece[i][n_j] = map[i][j];
    }
  }

  Piece tmp = {rd.second - lu.second + 1, rd.first - lu.first + 1, piece, cnt};

  game_board_piece.push_back(tmp);
}

int check(vector<vector<int>> &piece, int y, int x) {
  int size = game_board_piece.size();
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < 4; j++) {
      int test_y = game_board_piece[i].y;
      int test_x = game_board_piece[i].x;

      if (test_y == y && test_x == x) {
        vector<vector<int>> test_piece = game_board_piece[i].map;
        bool flag = true;
        for (int k = 0; k < 6; k++) {
          for (int z = 0; z < 6; z++) {
            if (test_piece[k][z] != piece[k][z]) {
              flag = false;
            }
          }
        }
        if (flag) {
          auto iter = game_board_piece.begin();
          iter += i;
          int cnt = game_board_piece[i].cnt;
          game_board_piece.erase(iter);
          return cnt;
        } else {
          game_board_piece[i].rotate();
        }

      } else {
        game_board_piece[i].rotate();
        continue;
      }
    }
  }
  return 0;
}

int find(pair<int, int> start, vector<vector<int>> &table) {
  int map[13][13] = {
      0,
  };
  int size = table.size();
  pair<int, int> lu = make_pair(0, 5), rd = make_pair(0, 5);
  queue<pair<int, int>> q;
  q.push(start);

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    if (lu.second > x - start.second + 5) {
      lu.second = x - start.second + 5;
    }

    if (rd.first < y - start.first) {
      rd.first = y - start.first;
    }

    if (rd.second < x - start.second + 5) {
      rd.second = x - start.second + 5;
    }
    table[y][x] = 0;
    map[y - start.first][x - start.second + 5] = 1;
    for (int i = 0; i < 4; i++) {
      int n_y = y + dy[i];
      int n_x = x + dx[i];

      if (0 <= n_x && 0 <= n_y && n_x < size && n_y < size &&
          table[n_y][n_x] == 1) {
        q.push(make_pair(n_y, n_x));
      }
    }
  }
  vector<vector<int>> piece(6, vector<int>(6, 0));
  for (int i = 0; i < rd.first + 1; i++) {
    for (int j = lu.second; j < rd.second + 1; j++) {
      int n_j = j - lu.second;
      piece[i][n_j] = map[i][j];
    }
  }

  return check(piece, rd.first - lu.first + 1, rd.second - lu.second + 1);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
  int answer = 0;
  int size = game_board.size();

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (game_board[i][j] == 0) {
        bfs(make_pair(i, j), game_board);
      }
    }
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (table[i][j] == 1) {
        answer += find(make_pair(i, j), table);
      }
    }
  }

  return answer;
}
int main() {
  vector<vector<int>> game_board;
  vector<vector<int>> table;
  game_board.push_back(vector<int>({1, 1, 0, 0, 1, 0}));
  game_board.push_back(vector<int>({0, 0, 1, 0, 1, 0}));
  game_board.push_back(vector<int>({0, 1, 1, 0, 0, 1}));
  game_board.push_back(vector<int>({1, 1, 0, 1, 1, 1}));
  game_board.push_back(vector<int>({1, 0, 0, 0, 1, 0}));
  game_board.push_back(vector<int>({0, 1, 1, 1, 0, 0}));

  table.push_back({1, 0, 0, 1, 1, 0});
  table.push_back({1, 0, 1, 0, 1, 0});
  table.push_back({0, 1, 1, 0, 1, 1});
  table.push_back({});
  table.push_back({});
  table.push_back({});
  solution(game_board, );
  return 0;
}
