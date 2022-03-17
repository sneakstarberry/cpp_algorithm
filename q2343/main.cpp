#include <iostream>
#include <vector>
#include <cmath>
#define MAX 100001
using namespace std;

typedef long long ll;

int N, M;
ll lessons[MAX];
ll l, h, m, t;


void input() 
{
  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    cin >> lessons[i];
    l = max(l, lessons[i]);
  }
}
int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  input();

  h = MAX * 10000;

  while(l <= h)
  {
    ll cnt = 0, tmp_sum = 0;
    m = (l + h) / 2;

    for (int i = 0; i < N; i++)
    {
      if(tmp_sum + lessons[i] > m)
      {
        tmp_sum = 0;
        cnt++;
      }

      tmp_sum += lessons[i];
    }
    if (tmp_sum != 0) cnt++;
    
    if (cnt <= M)
    {
      h = m-1;
      t = m;
    }
    else
    {
      l = m+1;
    }
  }

  cout << t;
  return 0;
}
