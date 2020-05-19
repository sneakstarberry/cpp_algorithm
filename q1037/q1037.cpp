#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    vector<int> val;
    int result;
    result = 1;
    
    cin >> N;

    for (int i=0; i < N; i++) {
        int tmp = 0;
        cin >> tmp;
        val.push_back(tmp);
    }

    sort(val.begin(), val.end());

    cout << val[0]*val[val.size() - 1] << endl;
    // cout << result << endl;

    return 0;
}