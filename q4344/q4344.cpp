#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int c, n, x, cnt, num;
    vector<int> vec;
    cin >> c;

    for (int i = 0; i < c; i++)
    {
        vec.clear();
        n = 0;
        num = 0;
        cnt = 0;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            x = 0;
            cin >> x;
            vec.push_back(x);
            num += vec[j];
        }
        int aver = num / n;
        for (vector<int>::size_type j = 0; j < vec.size(); j++)
        {
            if (aver < vec[j])
            {
                cnt++;
            }
        }

        cout.precision(3);
        cout << fixed << (double)cnt / n * 100 << "%" << endl;
    }
    return 0;
}