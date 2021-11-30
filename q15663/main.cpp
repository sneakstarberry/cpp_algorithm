#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> nums;
vector<int> vec;
bool is_visited[9] = {false,};
void dfs(int cnt) {
  if(cnt == M) {
    for(int i=0;i<M;i++) {
      cout << vec[i] << ' ';
    }
    cout << '\n';
    return;
  }
  int prev_num = -1;
  for (int i=0; i<N; i++) {
    if (is_visited[i] ) continue;
    if ( prev_num == nums[i]) continue;
    is_visited[i] = true;
    vec.push_back(nums[i]);
    prev_num = nums[i];
    dfs(cnt+1);
    vec.pop_back();
    is_visited[i] = false;
  }

}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    int tmp;
    
    cin >> tmp;
    nums.push_back(tmp);
  }
  sort(nums.begin(), nums.end());

  dfs(0);
  return 0;
}
