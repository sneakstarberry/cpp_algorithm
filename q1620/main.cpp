#include <iostream>
#include <unordered_map>
#define endl '\n'

using namespace std;
int N, M;

int is_num(string str);

int main() {
  std::cin.tie(0);
  std::cin.sync_with_stdio(false);
  std::cout.tie(0);
  std::cout.sync_with_stdio(false);
  unordered_map<string, string> string_to_search;

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    string pokemon;
    cin >> pokemon;
    string_to_search[pokemon] = to_string(i);
    string_to_search[to_string(i)] = pokemon;
  }

  for (int i = 0; i < M; i++) {
    string question;
    cin >> question;
    cout << (string_to_search[question]) << endl;
  }
}

int is_num(string str) {
  for (auto c : str) {
    if (isdigit(c) == 0) {
      return 0;
    }
  }
  return 1;
}