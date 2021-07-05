#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string input, char delimiter) {
  vector<string> answer;
  stringstream ss(input);
  string temp;

  while (getline(ss, temp, delimiter)) {
    answer.push_back(temp);
  }

  return answer;
}

vector<string> solution(vector<string> param) {
  vector<string> answer;
  vector<string> file_names;
  vector<int> again;
  vector<string> vec[101];

  int size = param.size();

  for (int i = 0; i < size; i++) {
    vec[i] = split(param[i], '/');
  }

  for (int i = 0; i < size; i++) {
    vec[i] = split(vec[i].back(), '_');

    if (vec[i].size() >= 2) {
      vector<string> extention = split(vec[i].back(), '.');
      vec[i][0] = vec[i][0] + '.' + extention.back();
    }
  }

  for (int i = 0; i < size; i++) {
    int flag = 0;
    for (int j = 0; j < file_names.size(); j++) {
      if (file_names[j] == vec[i][0]) {
        flag = 1;
        again[j]++;
      }
    }

    if (flag) {
      continue;
    } else {
      file_names.push_back(vec[i][0]);
      again.push_back(1);
    }
  }

  for (int i = 0; i < file_names.size(); i++) {
    if (again[i] > 1) {
      answer.push_back(file_names[i]);
      answer.push_back(to_string(again[i]));
    }
  }

  return answer;
}

int main() {
  vector<string> test1{"/a/a_v2.x", "/b/a.x",      "/c/t.z",
                       "/d/a/t.x",  "/e/z/t_v1.z", "/k/k/k/a_v9.x"};
  vector<string> answer = solution(test1);

  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i] << ' ';
  }
}