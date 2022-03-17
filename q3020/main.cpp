#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, h;
  int bot[100001], top[100001];
  cin >> n >> h;

  for (int i = 0; i < n/2; i++)
  {
    cin >> bot[i] >> top[i];
  }

  sort(bot, bot + n/2);
  sort(top, top + n/2);

  int ans = 200001;
  int num = 0;

  for (int i = 1; i <= h; i++)
  {
    int cnt = 0;

    int idx = lower_bound(bot, bot+n/2, i) - bot;
    cnt += n/2 - idx;

    idx = upper_bound(top, top + n/2, h-i) - top;
    cnt += n/2 - idx;

    if(ans == cnt) num++;
    if(ans > cnt)
    {
      ans = cnt;
      num = 1;
    }
  }
  
  cout << ans << ' ' << num;
  return 0;
}
