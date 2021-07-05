#include <algorithm>
#include <iostream>
#include <vector>

#define MAX (4000000 + 100)

using namespace std;

int N;
vector<int> prime;
long long numbers[MAX];
void set_prime_numbers() {

  for (long long i = 2; i < MAX; i++) {
    numbers[i] = i;
  }
  for (long long i = 2; i < MAX; i++) {
    if (numbers[i] == 0)
      continue;

    for (long long j = i * i; j < MAX; j += i) {
      if (j > MAX)
        continue;
      numbers[j] = 0;
    }
  }

  for (long long i = 2; i < MAX; i++) {
    if (!(numbers[i] == 0)) {
      prime.push_back(i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  set_prime_numbers();
  int low = 0, high = 0;
  int sum = prime[0];
  int cnt = 0;

  while (low <= high && prime[high] <= N) {
    if (sum < N) {
      sum += prime[++high];
    } else if (sum == N) {
      cnt++;
      sum += prime[++high];
    } else if (sum > N) {
      sum -= prime[low++];
    }
  }
  cout << cnt;
  return 0;
}