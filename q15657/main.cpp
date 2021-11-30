#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[9];
bool is_visited[9][9];
vector<int> vec;

void dfs(int cnt) {
  if( cnt >= M) {
    for (int i=0; i<M; i++) {
      cout << vec[i] << ' ';
    }
    cout << '\n';
    return;
  };

  for (int i=0; i<N; i++) {
    if(is_visited[cnt][i]) continue;
    if(!vec.empty() && (vec.back() > arr[i])) continue;
    vec.push_back(arr[i]);
    dfs(cnt+1);
    vec.pop_back();
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for (int i=0; i<N; i++) {
    cin >> arr[i];
  }
  sort(arr, arr+N);

  dfs(0);
  return 0;
}
