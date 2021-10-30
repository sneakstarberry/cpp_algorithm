#include <iostream>
#include <vector>
using namespace std;
int N, M, Q = 0;
int SOL[11] = {
    0,
};
int MIN = 11;
vector<int> member;

bool is_solved() {
  int solve = 1;
  for (int i=0; i<member.size(); i++) {
    solve |= SOL[member[i]];
  }

  if((solve & Q) == Q) {
    return true;
  } else {
    return false;
  }
}

void find( int index) {
  if (is_solved()) {
    if(MIN > member.size()) {
      MIN = member.size();
    }
    return;
  }
  for (int i=index; i<M; i++) {
    member.push_back(i);
    find(i+1);
    member.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;

  Q = (1 << (N+1)) - 1;
  for (int i=0; i<M; i++) {
    int cnt;
    cin >> cnt;

    for (int j=0; j<cnt; j++) {
      int tmp;
      cin >> tmp;
      SOL[i] |= 1 << tmp;
    }
  }

  find(0);

  if(11 == MIN) {
    cout << -1;
  } else {
    cout << MIN;
  }
  return 0;
}
