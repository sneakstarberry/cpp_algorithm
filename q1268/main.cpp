#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  vector<vector<int>> c_info(N + 1, vector<int>(5, 0));
  vector<vector<int>> c_point(5, vector<int>(10, 0));
  vector<int> s_point(N + 1, 0);

  //    vector<vector<int>> c_info(1001,vector<int>(1001, 0));
  //    vector<vector<int>> c_point(1001,vector<int>(1001, 0));
  //    vector<int> s_point (1001, 0);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> c_info[i][j];
    };
  }

  //    for(auto cs : c_info ) {
  //        for (auto c : cs) {
  //            cout << c << " ";
  //        }
  //        cout << endl;
  //    }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < N; j++) {
      c_point[i][c_info[j][i]]++;
    };
  }

  // cout << endl;
  // cout << endl;
  // for (auto cs : c_point) {
  //   for (auto c : cs) {
  //     cout << c << " ";
  //   }
  //   cout << endl;
  // }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 5; j++) {
      s_point[i] += c_point[j][c_info[i][j]];
      //            for (int w = 0; w < 5; w++ ) {
      //                s_point[i] += c_point[w][c_info[i][j]];
      //            };
    }
  }

  //    for (int i = 0; i < N; i++ ) {
  //        for (int j = 0; j < 5; j++ ) {
  //            s_point[i] += c_info[i][j];
  //        };
  //    }

  // cout << endl;
  // cout << endl;
  // for (auto i : s_point) {
  //   cout << i << " ";
  // }
  // cout << endl;
  // cout << endl;

  int max_index = max_element(s_point.begin(), s_point.end()) - s_point.begin();

  cout << max_index + 1 << endl;
  ;
  return 0;
};