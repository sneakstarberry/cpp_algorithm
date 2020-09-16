#include<iostream>
#include<algorithm>
using namespace std;

long long N, M, RESULT=0;
long long v[1000001];

int main(){
    long long start, end = 0, mid;

    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> v[i];
        if (end < v[i]) end = v[i];
    }

    start = 0;

    while(start <= end){
        mid = (start + end)/2;
        long long total = 0;
        for(int i=0; i < N; i++){
            if(mid < v[i]){
                total += v[i] - mid;
            }
        }

        if(total >= M){
            if(RESULT < mid) RESULT = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout << RESULT;

    return 0;
}