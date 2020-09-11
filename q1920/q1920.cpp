#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n"

int N, M;
vector<int> arr, target;

void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int tmp;
        cin >> tmp;
        target.push_back(tmp);
    }
    return;
}

void Solved()
{

    sort(arr.begin(), arr.end());
    for (int i = 0; i < M; i++)
    {
        int start, end, mid, rst = 0;
        start = 0;
        end = N - 1;
        mid = (end + start) / 2;

        while ((end - start) >= 0)
        {
            if (arr[mid] < target[i])
            {
                start = mid + 1;
                mid = (end + start) / 2;
            }
            else if (arr[mid] > target[i])
            {
                end = mid - 1;
                mid = (end + start) / 2;
            }
            else
            {
                rst = 1;
                break;
            }
        }
        cout << rst << endl;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio;
    cin.tie(0);

    init();
    Solved();

    return 0;
}