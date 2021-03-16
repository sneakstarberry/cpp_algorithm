#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 987654321;
const int MAX = 801;
int dist[MAX];
int N, E;
vector<pair<int, int>> vec[MAX];

vector<int> dijkstra(int start, int vertex);

int main()
{
    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cin >> N >> E;
    N++;
    int edge1, edge2, cost;
    for (int i = 0; i < E; i++)
    {
        cin >> edge1 >> edge2 >> cost;
        vec[edge1].push_back(make_pair(edge2, cost));
        vec[edge2].push_back(make_pair(edge1, cost));
    }

    int node1, node2;

    cin >> node1 >> node2;

    vector<int> result = dijkstra(1, N);
    vector<int> tmp1 = dijkstra(node1, N);
    vector<int> tmp2 = dijkstra(node2, N);

    int answer = min({ result[node1] + tmp1[node2] + tmp2[N - 1], result[node2] + tmp2[node1] + tmp1[N - 1] });

    if (answer >= INF || answer < 0){
        cout << -1 << '\n';
    } else {
        cout << answer << '\n';
    }

    return 0;
}

vector<int> dijkstra(int start, int vertex)
{

    vector<int> distance(vertex, INF);

    distance[start] = 0;

    priority_queue<pair<int, int>> pq;

    pq.push({0, start});

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (distance[cur] < cost)
            continue;
        for (int i = 0; i < vec[cur].size(); i++)
        {

            int next = vec[cur][i].first;
            int n_cost = cost + vec[cur][i].second;

            if (distance[next] > n_cost)
            {
                distance[next] = n_cost;
                pq.push({n_cost, next});
            }
        }
    }

    return distance;
}
