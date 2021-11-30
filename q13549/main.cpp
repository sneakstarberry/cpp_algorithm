#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

int N, K;

int is_visited[MAX];
int main()
{
  cin >> N >> K;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

  q.push(make_pair(0, N));
  is_visited[N] = 1;
  while (!q.empty()) {
    pair<int,int> top = q.top();
    q.pop();

    if (top.second == K) {
      cout << -top.first;
      return 0;
    }

    if (top.second * 2 < MAX && !is_visited[top.second*2]) {
      q.push(make_pair(top.first, top.second * 2));
      is_visited[top.second*2] = 1;
    }
    if(top.second + 1 < MAX && !is_visited[top.second + 1]) {
      q.push(make_pair(top.first - 1, top.second +1));
      is_visited[top.second + 1] = 1;
    }
    if(top.second - 1 >= 0 && !is_visited[top.second - 1]) {
      q.push(make_pair(top.first - 1, top.second - 1));
      is_visited[top.second - 1] = 1;
    }
    
  }
  
  return 0;
}

