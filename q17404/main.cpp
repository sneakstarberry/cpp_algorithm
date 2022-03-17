#include <iostream>
#include <vector>

using namespace std;
#define MAX 1001

int COSTS[MAX][MAX];
int N;

void input()
{
  cin >> N;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cin >> COSTS[i][j];
    }
  }
}
int main()
{
  input();
  return 0;
}



