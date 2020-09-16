#include <iostream>
using namespace std;

#define endl "\n"
#define INF 987654321
#define NIL -1
#define MAX 101

int graph[MAX][MAX];
int before[MAX][MAX];

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        for(int j=1;j<=N;j++){
            graph[i][j] = MAX;
            if (i == j) graph[i][j] = 0;
            before[i][j] = NIL;
        }
    }
    
    for(int i=0;i<M;i++){
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1][node2] = 1;
        graph[node2][node1] = 1;
        before[node1][node2] = node1;
        before[node2][node1] = node1;
    }
    for (int mid=1;mid<=N;mid++){
        for (int start=1;start<=N;start++){
            for (int end=1;end<=N;end++){
                if (graph[start][end] > graph[start][mid] + graph[mid][end]){
                    graph[start][end] = graph[start][mid] + graph[mid][end];
                    before[start][end] = before[mid][end];
                }
            }
        }
    }

    int sum=0;
    int min=MAX;
    int result;
    for (int i=1;i<=N;i++){
        sum=0;
        for (int j=1;j<=N;j++){
            sum+=graph[i][j];
        }
        if (min>sum){
          min = sum;
          result=i;
        }
    }
    cout << result << endl;


    return 0;
}