#include <iostream>
#include <vector>

using namespace std;

int main() {
  string target, bomb;
  string result = "";
  cin >> target >> bomb;
  auto cursor = target.begin();

  while (cursor != target.end()) {
    result.push_back(*cursor);
    if (result.length() < bomb.length()) {
      cursor++;
      continue;
    }
    if (result[result.length() - bomb.length()] == bomb[0]) {
      int is_match = 1;
      for (int i = result.length() - bomb.length(); result[i] != *result.end();
           i++) {
        if (result[i] != bomb[i + bomb.length() - result.length()]) {
          is_match = 0;
          break;
        }
      }
      if (is_match) {
        for (int i = 0; i < bomb.length(); i++) {
          result.pop_back();
        }
      }
    } else {
      cursor++;
      continue;
    }

    cursor++;
  }
  if (result != "") {
    cout << result;
  } else {
    cout << "FRULA";
  }
}
