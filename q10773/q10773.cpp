#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> nums;
    int result =0;
    for(int i=0; i < N; i++ ) {
        int tmp;
        cin >> tmp;
        if (tmp == 0){
            nums.pop_back();
        } else {
            nums.push_back(tmp);
        }
    }

    for (int i=0; i < nums.size(); i++) {
        result += nums[i];
    }
    cout << result << endl;
    return 0;

}