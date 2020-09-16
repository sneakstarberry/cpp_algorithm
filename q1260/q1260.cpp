#include <iostream>
#include <queue>
using namespace std;

#define endl "\n"

int N, M, V;
int arr[1001][1001]={0, };
bool visit[1001] = {false, };

void DFS (int s){
    int i = 0;

    cout << s << " ";
    visit[s] = true;

    for(i = 1; i<=N; i++) {
        if(arr[s][i] && !visit[i]){
            DFS(i);
        }
    }
    if(i==N) return;
}

void init() {
    for (int i=0; i<=1000; i++) visit[i] = false;
}

void BFS(int s) {
    queue <int> q;
    int i = 0;

    q.push(s);
    visit[s] = true;

    while(!q.empty()){
        int news = q.front();
        visit[news] = true;
        cout << news << " ";
        q.pop();

        for (i=1; i<=N;i++){
            if(arr[news][i] && !visit[i]){
                visit[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int src, dest;

    cin >> N >> M >> V;
    for(int i=1; i<=M; i++){
        cin >> src >> dest;
        arr[src][dest] = 1;
        arr[dest][src] = 1;
    }

    DFS(V);
    cout << endl;

    init();
    BFS(V);
    cout << endl;


    return 0;
}