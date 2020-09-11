#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int main() {
    string N;
    int num[10]={0,};
    int Max= 0;
    cin >> N;

    for (int i=0; i<N.length();i++){
        num[(int)N[i]-48]++;
    }
    num[6] = num[6] + num[9];
    num[6] = (num[6]+1)/2;
    for(int i=0; i<9; i++){
        Max = max(num[i], Max);
    }
    cout << Max << endl;
    return 0;
}