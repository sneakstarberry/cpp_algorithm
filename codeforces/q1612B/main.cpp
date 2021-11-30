#include <iostream>
#include <vector>

using namespace ::std;

int N;

struct Case {
  int n;
  int min;
  int max;
};
typedef Case Case;

Case cases[1001];
bool Flag = false;

void init() {
  cin >> N;

  for (int i=0; i<N; i++) {
    cin >> cases[i].n >> cases[i].min >> cases[i].max;
  }
};

vector<int> min_result(int i) {
  vector<int> result;
  int j=0;
  result.push_back(cases[i].min);
  if (cases[i].n == 2) {
    return result;
  }
  while(true) {
    int upper_value = cases[i].n - j;
    if (cases[i].max == upper_value || cases[i].min == upper_value) {
      j++;
      continue;
    }
    if (cases[i].min > upper_value) {
      Flag = true;
      break;
    }


    result.push_back(upper_value);
    j++;
    if (result.size() == cases[i].n/2) {
      break;
    }
  }

  return result;
}

vector<int> max_result(int i) {
  vector<int> result;
  int j=1;
  result.push_back(cases[i].max);
  if (cases[i].n == 2) {
    return result;
  }
  while(true) {
    int under_value = j;
    if (cases[i].min == under_value || cases[i].max == under_value) {
      j++;
      continue;
    }
    if(cases[i].max < under_value) {
      Flag = true;
      break;
    }
    

    result.push_back(under_value);
    j++;
    if(result.size() == cases[i].n/2) {
      break;
    }
  }

  return result;
}

void solve() {
  vector<int> result; 
  for (int i=0; i<N; i++) {
    result.clear();
    int j=0;
    Flag = false;
    vector<int> min_vec = min_result(i);
    vector<int> max_vec = max_result(i);
    if (Flag) {
      cout << -1 << '\n';
    } else {
      for (int i=0; i<min_vec.size(); i++) {
        result.push_back(min_vec[i]);
      }
      for (int i=0; i<max_vec.size(); i++) {
        result.push_back(max_vec[i]);
      }
      for (int i=0; i<result.size(); i++) {
        cout << result[i] << ' ';
      }
      cout << '\n';
    }
  }
}

int main()
{
  init();

  solve();
  return 0;
}
