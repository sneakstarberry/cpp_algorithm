#include <iostream>
using namespace std;

int main()
{
    int result[100][100];
    int N, M;
    cin >> N >> M;
    int A[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }
    int K;
    cin >> M >> K;
    int B[M][K];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            for (int K = 0; K < M; K++)
            {
                result[i][j] += (A[i][K] * B[K][j]);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}