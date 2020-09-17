#include <iostream>
#include <string>
using namespace std;
#define endl "\n"

int N;
string arr[64], s;
void init() {
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    return;
}

void quadtree(int x, int y, int size){
    int start = arr[y][x];
    bool flag=true;
    for(int i =y; (i < y+size) && flag; i++){
        for(int j=x;(j < x+size) && flag; j++){
            if(arr[i][j] != start){
                flag = false;
            }
        }
    }
    if(flag){
        cout << char(start);
    } else {
        cout << "(";
        quadtree(x,y,size/2);
        quadtree(x+size/2,y,size/2);
        quadtree(x,y+size/2,size/2);
        quadtree(x+size/2,y+size/2,size/2);
        cout << ")";
    }
    return;
}

int main() {
    ios_base::sync_with_stdio;
    cin.tie(0);

    init();
    
    quadtree(0, 0, N);
    return 0;
}