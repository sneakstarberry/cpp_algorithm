#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
// - 5 ≤ n ≤ 1,000,000
// - 0 ≤ k < n
// - 1 ≤ cmd의 원소 개수 ≤ 200,000
// - cmd의 각 원소는 "U X", "D X", "C", "Z" 중 하나입니다.
// - X는 1 이상 300,000 이하인 자연수이며 0으로 시작하지 않습니다.
// - X가 나타내는 자연수에 ',' 는 주어지지 않습니다. 예를 들어 123,456의 경우
// 123456으로 주어집니다.
// - cmd에 등장하는 모든 X들의 값을 합친 결과가 1,000,000 이하인 경우만 입력으로
// 주어집니다.
// - 표의 모든 행을 제거하여, 행이 하나도 남지 않는 경우는 입력으로 주어지지
// 않습니다.
// - 본문에서 각 행이 제거되고 복구되는 과정을 보다 자연스럽게 보이기 위해
// "이름" 열을 사용하였으나, "이름"열의 내용이 실제 문제를 푸는 과정에
// 필요하지는 않습니다. "이름"열에는 서로 다른 이름들이 중복없이 채워져 있다고
// 가정하고 문제를 해결해 주세요.
// - 표의 범위를 벗어나는 이동은 입력으로 주어지지 않습니다.
// - 원래대로 복구할 행이 없을 때(즉, 삭제된 행이 없을 때) "Z"가 명령어로
// 주어지는 경우는 없습니다.
// - 정답은 표의 0행부터 n - 1행까지에 해당되는 O, X를 순서대로 이어붙인 문자열
// 형태로 return 해주세요.

string solution(int n, int k, vector<string> cmd) {
  string answer = "";
  int cursor = k;
  stack<int> deleted;

  for (int i = 0; i < n; i++) {
    answer.push_back('O');
  }

  for (int i = 0; i < cmd.size(); i++) {
    int move = 0;
    char command = cmd[i][0];

    if (command == 'D') {
      for (int j = 2; j < cmd[i].size(); j++) {
        move *= 10;
        move += cmd[i][j] - '0';
      }
      for (int j = 0; j < move; j++) {
        if (answer[++cursor] == 'X') {
          ++cursor;
        }
      }
    } else if (command == 'C') {
      int flag = 0;
      deleted.push(cursor);
      answer[cursor] = 'X';

      while (answer[++cursor] == 'X') {
      }
      if (cursor >= n) {
        flag = 1;
      }
      if (flag) {
        cursor = deleted.top();
        while (answer[--cursor] == 'X') {
        }
      }
    } else if (command == 'U') {
      for (int j = 2; j < cmd[i].size(); j++) {
        move *= 10;
        move += cmd[i][j] - '0';
      }
      for (int j = 0; j < move; j++) {
        if (answer[--cursor] == 'X') {
          --cursor;
        }
      }
    } else if (command == 'Z') {
      int restore_num = deleted.top();
      deleted.pop();

      answer[restore_num] = 'O';
    }
  }

  return answer;
}

int main() {
  vector<string> test = {"D 11", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"};
  cout << solution(20, 2, test);
}