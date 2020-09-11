#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Answer;
int Amenu[200000];
int Bmenu[200000];
vector <int> v;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

        int N, K;
        cin >> N >> K;
        Answer = 0;

        for (int i=0;i<N;i++){
            cin >> Amenu[i];
        }
        sort(Amenu,Amenu+N);
        for (int i=0;i<N;i++){
            cin >> Bmenu[i];
        }
        sort(Bmenu,Bmenu+N);

        for(int i=0; i<K;i++){
            v.push_back(Amenu[i] + Bmenu[K-1-i]);
        }

        sort(v.begin(),v.end());
        Answer=v[K-1];
        v.clear();
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }
    return 0;
}