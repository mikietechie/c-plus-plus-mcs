#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // (distance, vertex)

vector<int> dijkstra(const vector<vector<pii>> &graph, int start, int n)
{
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_dist > dist[u])
            continue;

        for (const auto &edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{

    int n, m;
    std::cin >> n >> m;
    int s, t;
    std::cin >> s >> t;

    vector<vector<pii>> graph(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int b, e, w;
        std::cin >> b >> e >> w;
        graph[b].emplace_back(e, w);
        graph[e].emplace_back(b, w); // Undirected graph
    }

    vector<int> dist = dijkstra(graph, s, n);
    if (dist[t] == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dist[t] << endl;
    }

    return 0;
}