#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    int card[N];
    bool flag=false;

    for(int i=0; i<N; i++){
        cin >> card[i];
    }
    sort(card, card + N);
    cin >> M;
    int shot[M];
    for(int i=0; i<M; i++){
        cin >> shot[i];
    }

    for(int i=0; i<M; i++){
        flag = false;
        int start =0, end = N-1;
        int mid = (end-start)/2;
        while(end-start >=0){
            if(card[mid] == shot[i]){
                shot[i] = 1;
                flag = true;
                break;
            } else if (card[mid] <= shot[i]){
                start = mid + 1;
            } else {
                end = mid -1;
            }
            mid = (end+start)/2;
        }
        if(!flag){
            shot[i] = 0;
        }
    }

    for (int i=0; i<M; i++){
        cout << shot[i] << " ";
    }
    cout << endl;
    return 0;
}