#include <iostream>
#include <string>
#include <vector>

using namespace std;

string K;
string S;
int N;
vector<string> arr;

void input(){
    cin >> K >> S >> N;

    for (int i=0; i<N; i++){
        string tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
}

void r(){
    K[0] += 1;
    if(K == S){
        S[0] += 1;
    }
    if (S[0] == 'I'){
        S[0] -= 1;
        K[0] -= 1;
    }
    if (K[0] == 'I'){
        K[0] -= 1;
    }
}
void l(){
    K[0] -= 1;
    if (K == S){
        S[0] -= 1;
    }
    if (S[0] == 64){
        S[0] += 1;
        K[0] += 1;
    }
    if(K[0] == 64){
        K[0] += 1;
    }
}

void b(){
    K[1] -= 1;
    if (K == S){
        S[1] -= 1;
    }
    if(S[1]=='0'){
        S[1] += 1;
        K[1] += 1;
    }
    if(K[1] == '0'){
        K[1] += 1;
    }
}
void t(){
    K[1] += 1;
    if (K == S){
        S[1] += 1;
    }
    if(S[1]=='9'){
        S[1] -= 1;
        K[1] -= 1;
    }
    if(K[1] =='9'){
        K[1] -= 1;
    }
}

void rt(){
    K[0] += 1;
    K[1] += 1;

    if(K == S){
        S[0] += 1;
        S[1] += 1;
    }

    if(S[0]=='I' || S[1] == '9'){
        S[0] -= 1;
        S[1] -= 1;
        K[0] -= 1;
        K[1] -= 1;
    }
    if(K[0]=='I' || K[1] == '9'){
        K[0] -= 1;
        K[1] -= 1;
    }
}
void lt(){
    K[0] -= 1;
    K[1] += 1;

    if(K == S){
        S[0] -= 1;
        S[1] += 1;
    }

    if(S[0]== 64 || S[1] == '9'){
        S[0] += 1;
        S[1] -= 1;
        K[0] += 1;
        K[1] -= 1;
    }
    if(K[0]== 64 || K[1] == '9'){
        K[0] += 1;
        K[1] -= 1;
    }
}

void rb(){
    K[0] += 1;
    K[1] -= 1;

    if(K == S){
        S[0] += 1;
        S[1] -= 1;
    }

    if(S[0]=='I' || S[1] == '0'){
        S[0] -= 1;
        S[1] += 1;
        K[0] -= 1;
        K[1] += 1;
    }
    if(K[0]=='I' || K[1] == '0'){
        K[0] -= 1;
        K[1] += 1;
    }
}

void lb(){
    K[0] -= 1;
    K[1] -= 1;

    if(K == S){
        S[0] -= 1;
        S[1] -= 1;
    }

    if(S[0]==64 || S[1] == '0'){
        S[0] += 1;
        S[1] += 1;
        K[0] += 1;
        K[1] += 1;
    }
    if(K[0]==64 || K[1] == '0'){
        K[0] += 1;
        K[1] += 1;
    }
}

int main(){

    input();
    
    for (int i=0; i<arr.size(); i++ ){
        string M = arr[i];

        if(M == "R"){
            r();
        } else if(M == "L"){
            l();
        } else if(M == "B"){
            b();
        } else if(M == "T") {
            t();
        } else if(M == "RT"){
            rt();
        } else if(M == "LT"){
            lt();
        } else if(M == "RB"){
            rb();
        } else if(M == "LB"){
            lb();
        }
    }

    cout << K << '\n';
    cout << S << '\n';


    return 0;
}