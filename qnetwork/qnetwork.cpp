#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int is_all_travers(vector<int> is_visited);
int unread_node(vector<int> is_visited);

int solution(int n, vector<vector<int> > computers) {
    int answer = 0;
    queue<int> q;
    vector<int> is_visited(n, 0);
    while(is_all_travers(is_visited)){
        q.push(unread_node(is_visited));
        answer++;
        while(!q.empty()) {
            int currentNode = q.front();
            is_visited[currentNode] = 1;
            q.pop();
            for(int i=0; i<n; i++) {
                if(i == currentNode){
                    continue;
                }
                if(!is_visited[i] && computers[currentNode][i]) {
                    q.push(i);
                }
            }
        }
    }
    return answer;
}

int main() {
  cout << 'a' << endl;
  vector<int> a;
  a.push_back(1);
  a.push_back(1);
  a.push_back(0);
  vector<int> b;
  b.push_back(1);
  b.push_back(1);
  b.push_back(0);
  vector<int> c;
  c.push_back(0);
  c.push_back(0);
  c.push_back(1);
  vector<vector<int> > computers(3,vector <int>(3,0));
  computers[0] = a;
  computers[1] = b;
  computers[2] = c;

  cout << solution(3, computers ) << endl;
  return 0;
}

int unread_node(vector<int> is_visited) {
    for(int i=0; i<is_visited.size(); i++) {
        if(!is_visited[i]){
            return i;
        }
    }
    return 0;
}


int is_all_travers(vector<int> is_visited){
    for(int i=0; i<is_visited.size(); i++){
        if(!is_visited[i]) {
            return 1;
        }
    }
    return 0;
}
