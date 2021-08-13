#include <iostream>
#include <vector>

using namespace std;

int N,M,K;
int Parents[51];
vector<int> Know;
vector<int> v[51];

int Find(int x) {
  if(Parents[x] == x) return x;
  else return Parents[x] = Find(Parents[x]);
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  Parents[x] = y;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> K;

  while( K--) {
    int t;
    cin >> t;
    Know.push_back(t);
  }

  for(int i=1; i<=N;i++) Parents[i] = i;

  for(int i=0;i<M;i++) {
    int p;
    cin >> p;
    int num;
    int prev;
    for(int j=0;j<p;j++) {
      if(j>=1) {
        prev=num;
        cin>>num;
        Union(prev, num);
      } else {
        cin >> num;
      }
      v[i].push_back(num);
    }
  }
  for(auto list:v) {
    bool flag = false;
    for(auto person:list) {
      if (flag) break;
      for(auto t : Know)  {
        if(Find(person) == Find(t)) {
          flag = true;
          break;
        }
      }
    }
    if(flag) M--;
  }
  cout << M;
  
  return 0;
}