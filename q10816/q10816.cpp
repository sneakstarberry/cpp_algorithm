#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> CARD, T;

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        CARD.push_back(tmp);
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int tmp;
        cin >> tmp;
        T.push_back(tmp);
    }
}

int main(){
    input();
    vector<int> v;
    vector<int>::iterator low;
    vector<int>::iterator upper;

    sort(CARD.begin(), CARD.end());


    for (int i = 0; i < M; i++) {
        low = lower_bound(CARD.begin(), CARD.end(), T[i]);
        upper = lower_bound(CARD.begin(), CARD.end(), T[i] + 1);

        cout << upper - low << ' ';
    }
}