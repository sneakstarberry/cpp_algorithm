#include <algorithm>
#include <string>
#include <vector>


using namespace std;
int ADS_EXPOSE = 5;
int compare(vector<int> a, vector<int> b) {
  if (a[0] == b[0]) {
    return a[1] > b[1];
  }
  return b[0] > a[0];
}
int solution(vector<vector<int>> ads) {
  int answer = 0;
  int cur_seconds = 0;
  sort(ads.begin(), ads.end(), compare);
  cur_seconds = ads[0][0];
  for (int i = 0; i < ads.size(); i++) {
    if (cur_seconds > ads[i][0]) {
      answer += ads[i][1] * (cur_seconds - ads[i][0]);
    }
    cur_seconds += ADS_EXPOSE;
  }
  return answer;
}

int main() {
  vector<vector<int>> a = {{1, 3}, {5, 4}, {3, 2}};

  solution(a);
}