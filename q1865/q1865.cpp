#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define endl "\n"
#define MAX 501

struct edge
{
    int from;
    int to;
    int cost;
};
int N, M, W;
int Dist[MAX];
vector<edge> Edge;
string answer;

void Input()
{
    cin >> N >> M >> W;
    for (int j = 0; j < M; j++)
    {
        edge tmp;
        cin >> tmp.from >> tmp.to >> tmp.cost;
        Edge.push_back(tmp);
        edge tmp2;
        tmp2.from = tmp.to;
        tmp2.to = tmp.from;
        tmp2.cost = tmp.cost;
        Edge.push_back(tmp2);
    }
    for (int j = 0; j < W; j++)
    {
        edge tmp;
        cin >> tmp.from >> tmp.to >> tmp.cost;
        tmp.cost = -tmp.cost;
        Edge.push_back(tmp);
    }
}

void Solved()
{
    Dist[1] = 0;
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 0; j < Edge.size(); j++)
        {
            int From = Edge[j].from;
            int To = Edge[j].to;
            int Cost = Edge[j].cost;

            if (Dist[From] == 0)
                continue;
            if (Dist[To] > Dist[From] + Cost)
                Dist[To] = Dist[From] + Cost;
        }
    }

    for (int i = 0; i < Edge.size(); i++)
    {
        int From = Edge[i].from;
        int To = Edge[i].to;
        int Cost = Edge[i].cost;

        if (Dist[From] == 0)
            continue;
        if (Dist[To] > Dist[From] + Cost)
        {
            answer = "YES";
            return;
        }
    }
    answer = "NO";
}

void Initialize()
{
    Edge.clear();
    memset(Dist, -1, sizeof(Dist));
}
int main()
{
    int TC; cin >> TC;
    for (int i = 0; i < TC; i++)
    {
        Initialize();
        Input();
        Solved();
        cout << answer << endl;
    }

    return 0;
}