#include <iostream>
#include <vector>
using namespace std;
struct Test {
  int n,m; vector<vector<int>>v;
  Test(int n, int m) : n(n), m(m), v(n, vector<int>(m)) {}

	vector<int>& operator[] (int i) { return v[i]; }
};
int main() {
  Test test(3,3);
  for(int i=0; i<3;i++ ) {
    for(int j=0;j<3;j++) {
      cout << test[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
int calculate(int in_time, int out_time, int basic_min,int basic_fee,int min,int min_per_fee){
    int result = 0;
    int during_time = out_time - in_time;
    
    if(during_time >= basic_min) {
        result += basic_fee;
        during_time -= basic_min;
        // 요금을 내는 횟 수
        int fee_times = during_time / min;
        result += min_per_fee*fee_times;
    }
    
    return result;
}