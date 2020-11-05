#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;

int N, M;
int check[1001][1001][2] = {
    0,
},
    dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
char arr[1001][1001];

int bfs()
{
    check[1][1][1]=1;
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(1, 1), 1));

    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int block = q.front().second;

        q.pop();
        
        if(y == N && x == M){
            return check[y][x][block];
        }

        for (int k = 0; k < 4; k++)
        {
            int newX = x + dx[k];
            int newY = y + dy[k];

            if (1 <= newX && newX <= M && 1 <= newY && newY <= N )
            {
                if(arr[newY][newX] == '1' && block){
                    check[newY][newX][block-1] = check[y][x][block] + 1;
                    q.push(make_pair(make_pair(newY, newX), block - 1));
                }
                if(arr[newY][newX] == '0' && check[newY][newX][block] == 0 ){
                    check[newY][newX][block] = check[y][x][block] + 1;
                    q.push(make_pair(make_pair(newY, newX), block));
                }
            }
        }
    }
    return -1;
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> &arr[i][1];

    cout << bfs() << endl;
    
}