
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int A, B;

int main(){
  cin >> A >> B;

  
  queue<pair<int, int> > q;
  q.push(make_pair(A, 1));

  while(!q.empty()) {
    int num = q.front().first;
    int time = q.front().second;

    q.pop();
    if(num > B) {
      continue;
    }
    if(num == B) {
      cout << time;
      return 0;
    }
    
    q.push(make_pair(num*2, time+1));
    if ((to_string(num)+"1").size() > 9) {
      continue;
    }
    q.push(make_pair(stoi(to_string(num)+"1"), time+1)); 
  }

  cout << "-1";
  return 0;
}



