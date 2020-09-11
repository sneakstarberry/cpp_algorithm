#include <iostream>
#include <vector>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int n, k;
        vector<int> x, y;
		Answer = 0;
        cin >> n >> k;

        for(int i=0; i<n;i++){
            int tmp;
            cin >> tmp;
            x.push_back(tmp);
        }
        for(int i=0; i<n;i++){
            int tmp;
            cin >> tmp;
            y.push_back(tmp);
        }

        
        if(n == 0){
            cout << "Case #" << test_case+1 << endl;
            cout << 1 << 0 << endl;
            break;
        }
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;