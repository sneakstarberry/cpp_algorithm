#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(string inputString) {
  int answer = 0;
  string s = "";

  for (int i = 0; i < inputString.size(); i++) {
    if (!(inputString[i] == '[' || inputString[i] == '{' ||
          inputString[i] == '(' || inputString[i] == '<' ||
          inputString[i] == ']' || inputString[i] == '}' ||
          inputString[i] == ')' || inputString[i] == '>')) {
      continue;
    } else if (inputString[i] == '[' || inputString[i] == '{' ||
               inputString[i] == '(' || inputString[i] == '<') {
      answer++;
      s.push_back(inputString[i]);
    } else if ((inputString[i] == ']' && s.back() == '[') ||
               (inputString[i] == '}' && s.back() == '{') ||
               (inputString[i] == ')' && s.back() == '(') ||
               (inputString[i] == '>' && s.back() == '<')

    ) {
      s.pop_back();
    } else {
      answer = -i;
      return answer;
    }
  }
  if (s.size() != 0) {
    answer = -(inputString.size() - 1);
  }
  return answer;
}

int main() {
  solution("line [({<plus>)}]");
  return 0;
}