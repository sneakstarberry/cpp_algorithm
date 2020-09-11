#include <iostream>
#include <string>
using namespace std;
int map[129][129];
int w_cnt = 0, b_cnt = 0;

void div_conq(int x, int y, int N)
{
    int tmp_cnt = 0;
    int color = map[x][y];
    for (int i = x; i < x + N; i++)
    {
        for (int j = y; j < y + N; j++)
        {
            if (map[i][j] != color)
            {
                div_conq(x, y, N / 2);
                div_conq(x, y + N / 2, N / 2);
                div_conq(x + N / 2, y, N / 2);
                div_conq(x + N / 2, y + N / 2, N / 2);
                return;
            }
        }
    }
    if (color == 1) b_cnt++;
    else w_cnt++;
}

int main()
{
    int n;
    cin >> n;
    for (int i=0; i< n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }
    div_conq(0,0, n);
    cout << w_cnt << endl << b_cnt << endl;
    return 0;
}