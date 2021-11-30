#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAX = 100 + 1;

 

int N, M;

string cache[MAX][MAX];

string big_int_add(string num1, string num2) {
  string result;
  long long sum = 0;

  while(!num1.empty() || !num2.empty() || sum) {
    if (!num1.empty()) {
      sum += num1.back() - '0';
      num1.pop_back();
    }

    if (!num2.empty()) {
      sum += num2.back() - '0';
      num2.pop_back();
    }
    result.push_back((sum % 10) + '0');
    sum /= 10;
  }
  reverse(result.begin(), result.end());
  return result;
}

string combination(int n, int m){
  if(n == m || m ==0) {
    return "1";
  }
  string &result = cache[n][m];

  if(result != "") {
    return result;
  }

  result = big_int_add(combination(n-1, m-1), combination(n-1, m));

  return result;
}

int main()
{
  cin >> N >> M;
  
  cout << combination(N, M) << '\n';
  
  return 0;
}
