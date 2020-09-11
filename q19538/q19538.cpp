#include <iostream>
#include<vector>

using namespace std;

int N, M;
bool END = true;

vector<int> VEC[200001];
vector<int> ZERO, Container, COUNT;

void input() {
    cin >> N;

    for (int i=0; i<N; i++) {
        while (1) {
            int tmp;
            cin >> tmp;
            if(!tmp) break;
            VEC[i].push_back(tmp);
        }
        COUNT.push_back(1);
    }

    cin >> M;

    for (int i=0; i<M; i++) {
        int tmp;
        cin >> tmp;
        ZERO.push_back(tmp);
    }

    Container = ZERO;

    for(int i=0; i<ZERO.size(); i++){
        COUNT[ZERO[i]-1] = 0;
    }
}

void infect(){
    vector<int> mock = Container;
    for (int i=0; i< N; i++){
        bool flag = false;
        for(int l=0; l<mock.size(); l++){
            if(i+1 == mock[l]){
                flag = true;
                break;
            }
        }

        if(flag || arr[i].size()==1){
            continue;
        }

        int count = 0;
        for(int j=0; j< arr[i].size()-1; j++){
            for(int k=0; k<mock.size(); k++){
                if(arr[i][j] == mock[k]){
                    count++;
                }
            }
        }

        if(arr[i].size()/2 <= count){
            Container.push_back(i+1);
            END = true;
        }
    }

    for(int i=0; i< N; i++){
        COUNT[i]++;
    }

    for(int i=0; i < Container.size(); i++){
        COUNT[Container[i]-1]--;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
    input();

    while (END) {
        END = false;
        infect();
    }
    vector<int> check;
    for(int i=0; i<N; i++){
        check.push_back(0);
    }
    for(int i=0; i<Container.size(); i++){
        check[Container[i]-1]=1;
    }
    for(int i=0; i<N; i++){
        if(check[i] == 0){
            COUNT[i] = -1;
        }
    }
    for(int i=0; i< N; i++){
        cout << COUNT[i] << ' ';
    }

    return 0;
}