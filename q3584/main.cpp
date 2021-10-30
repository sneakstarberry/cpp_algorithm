#include <iostream>
#include <vector>

using namespace std;


int main() {
	int T,N;
	cin >> T;
	for (int t = 0;t < T;t++) {
		cin >> N;
		vector<int> my_parent(10001, 0);
		for (int n = 0;n < N-1;n++) {
			int A, B;
			cin >> A >> B;
			my_parent[B] = A;
		}
		int a, b;
		cin >> a >> b;
		// 루트까지 거슬러 올라가기 
		vector<int> _a; //A ~ 루트까지 거슬러 올라가는 경로 저장 
		vector<int> _b; //B ~ 루트까지 거슬러 올라가는 경로 저장 
		int now = a;
		while (now != 0) {
			_a.push_back(now);
			now = my_parent[now];
		}
		now = b;
		while (now != 0) {
			_b.push_back(now);
			now = my_parent[now];
		}

		// 가장 가까운 공통 조상 찾기 
		bool isFind = false;
		for (int i = 0;i < _a.size();i++) {
			if (isFind) break;
			for (int j = 0;j < _b.size();j++) {
				if (_a[i] == _b[j]) {
					cout << _a[i] << endl;
					isFind = true;
					break;
				}
			}
		}
	}

}
