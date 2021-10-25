#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int N;
ll ans = 0;
int v[500011], tmp[500011];

void merge(int left, int mid, int right) {
  int idx = left;
  int i = left, j = mid+1;
  int cnt = 0;
  
  while(i<=mid | j<=right) {
    if(i > mid) {
      tmp[idx++] = v[j++]; cnt++;
    } else if (j > right) {
      tmp[idx++] = v[i++]; ans +=(ll) cnt;
    } else if (v[i] <= v[j]) {
      tmp[idx++] = v[i++]; ans += (ll) cnt;
    } else {
      tmp[idx++] = v[j++]; cnt++;
    }
  }
  for(i=left; i<=right; i++) v[i] = tmp[i];
};

void merge_sort(int left, int right) {
  int mid;
  if(left < right) {
    mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid+1, right);
    merge(left, mid, right);
  }
}



int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for (int i=0; i<N; i++) {
    cin >> v[i];
  }

  merge_sort(0, N-1);
  cout << ans;
  
  return 0;
}
