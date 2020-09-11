#include <iostream>
using namespace std;

int N, M, cnt;
int arr[101][101] = {0,};
bool visit[101] = {false,};

void DFS(int s) {
    visit[s] = true;
    cnt +=1;

    for(int i = 1; i<=N; i++) {
        if(arr[s][i] && !visit[i]){
            DFS(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio;
    cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int start, end;
        cin>>start>>end;
        arr[start][end] = 1;
        arr[end][start] = 1;
    }

    DFS(1);

    cout << cnt-1;


    return 0;
}