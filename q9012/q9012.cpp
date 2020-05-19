#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main () {
    int n;
    string s;
    vector<string> vec;
    int cnt =0;
    cin >> n;
    for (int i=0; i< n; i++) {
        cin >> s;
        vec.push_back(s);
        for(int j=0; j<s.size(); j++) {
            if (s[j] == '(' && cnt != -1){
                cnt++;
            } else{
                cnt--;
            }
        }
        if (cnt == 0){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        cnt = 0;
    }
    return 0;
}