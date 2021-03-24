#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int T;
int ARR[100001];

int main() {
  int n, m;
  vector<int> vec;
  vector<int> mVec;
  int cnt = 0, m_cnt = 0;

  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> n >> m;
    memset(ARR, 0, sizeof(ARR));
    m_cnt = 0;
    for (int j = 0; j < n; j++) {
      int temp;
      cin >> temp;
      vec.push_back(temp);
    }

    for (int j = 0; j < vec.size(); j++) {
      if (ARR[j]) {
        continue;
      }
      mVec.clear();
      cnt = 0;
      mVec.push_back(vec[j]);
      ARR[j] = 1;
      for (int k = j; k < vec.size(); k++) {
        if (ARR[k]) {
          continue;
        }
        if ((mVec[cnt] + vec[k]) % m == 0) {
          ARR[k] = 1;
          mVec.push_back(vec[k]);
          cnt++;
          k = 0;
        }
      }
      if (mVec.size() <= 1)
        ARR[j] = 0;
      else
        m_cnt++;
    }
    cnt = 0;

    for (int j = 0; j < vec.size(); j++) {
      if (ARR[j]) {
        continue;
      } else {
        cnt++;
      }
    }
    if (cnt == 1) {
      m_cnt++;
    }

    cout << m_cnt << endl;

    vec.clear();
  }
}