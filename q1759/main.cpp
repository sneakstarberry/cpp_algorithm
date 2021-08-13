#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

char letters[16];
int L, C;

bool is_mo(char letter) {
  if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' ||
      letter == 'u') {
    return true;
  } else {
    return false;
  }
}

void dfs(int start, string cipher, int mo, int ja) {
  if (cipher.size() == L) {
    if (mo >= 1 && ja >= 2)
      cout << cipher << endl;
    return;
  }

  for (int i = start; i <= C; i++) {
    if (is_mo(letters[i])) {
      dfs(i + 1, cipher + letters[i], mo + 1, ja);
    } else {
      dfs(i + 1, cipher + letters[i], mo, ja + 1);
    }
  }
}

int main() {

  cin >> L >> C;

  for (int i = 1; i <= C; i++) {
    cin >> letters[i];
  }

  sort(letters, letters + C + 1);

  dfs(1, "", 0, 0);

  return 0;
}