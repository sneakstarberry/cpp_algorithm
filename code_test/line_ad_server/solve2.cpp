#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
  stack<pair<int, int>> st;
  int size = array.size();
  vector<int> answer(size);
  vector<int> l_vec(size);
  vector<int> r_vec(size);

  for (int i = 0; i < size; i++) {
    while (!st.empty()) {
      if (st.top().second > array[i]) {
        l_vec[i] = st.top().first;
        break;
      }
      st.pop();
    }
    if (st.empty()) {
      l_vec[i] = (-1);
    }
    st.push({i, array[i]});
  }

  while (!st.empty()) {
    st.pop();
  }

  for (int i = size - 1; i >= 0; i--) {
    while (!st.empty()) {
      if (st.top().second > array[i]) {
        r_vec[i] = st.top().first;
        break;
      }
      st.pop();
    }
    if (st.empty()) {
      r_vec[i] = -1;
    }
    st.push({i, array[i]});
  }

  for (int i = 0; i < size; i++) {
    cout << answer[i] << ' ';
  }

  return answer;
}

int main() {
  vector<int> a = {3, 5, 4, 1, 2};
  solution(a);

  return 0;
}