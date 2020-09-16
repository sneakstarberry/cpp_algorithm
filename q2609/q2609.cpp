#include <iostream>
using namespace std;

int N, M;

void change(int* a, int* b){
    if (a<b){
        int* tmp = a;
        a=b;
        b=tmp;
        return;
    } else {
        return;
    }
};

int gcd(int a, int b){
    while(true){
        if(b == 0) break;
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
};

int main(){
    cin >> N >> M;
    change(&N ,&M);
    int result = gcd(N, M);
    cout << result << "\n";
    cout << N*M/result << "\n";

    return 0;
}
