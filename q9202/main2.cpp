#include <iostream>
#include <unordered_map>
#include <unordered_set>

#define endl '\n'

using namespace std;

int sc[] = {0, 0, 1, 1, 2, 3, 5, 11};
int dx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int is_visited[4][4], W, B, SCORE;
string board[4], longest;
unordered_set<string> boggled;
unordered_map<string, int[31]> WORDS;

// dfs
void search(int y, int x, string s, int t) {
  if (s.length() > 8)
    return;
  if (WORDS[s][30] && !WORDS[s][t]) {
    WORDS[s][t] = true;
    boggled.insert(s);
  }
  if (is_visited[y][x]) {
    return;
  }
  is_visited[y][x] = 1;

  int _idx = board[y][x] - 'A';

  s.push_back(board[y][x]);

  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (0 > nx || nx > 3 || 0 > ny || ny > 3)
      continue;
    search(ny, nx, s, t);
  }
  s.pop_back();
  is_visited[y][x] = 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> W;
  while (W--) {
    string s;
    cin >> s;
    WORDS[s][30] = 1;
  }

  cin >> B;

  while (B--) {

    for (int i = 0; i < 4; i++) {
      cin >> board[i];
    }
    SCORE = 0;
    longest = "";
    boggled.clear();

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        search(i, j, "", B);
      }
    }
    for (string boggle : boggled) {
      if (boggle.length() > longest.length() ||
          boggle.length() == longest.length() && longest > boggle)
        longest = boggle;
      SCORE += sc[boggle.length() - 1];
    }
    cout << SCORE << ' ' << longest << ' ' << boggled.size() << endl;
  }
  return 0;
}