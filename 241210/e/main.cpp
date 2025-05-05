// author mike

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, S, F;
    std::cin >> N >> S >> F;
    S--;
    F--; // converting to 0-based index

    vector<vector<pair<int, int>>> graph(N);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int weight;
            std::cin >> weight;
            if (weight != -1 && i != j)
            {
                graph[i].emplace_back(j, weight);
            }
        }
    }

    vector<int> dist(N, INF);
    dist[S] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});

    while (!pq.empty())
    {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (u == F)
            break; // reached the target vertex

        if (current_dist > dist[u])
            continue; // already found a better path

        for (auto &edge : graph[u])
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

    if (dist[F] == INF)
    {
        std::cout << -1 << endl;
    }
    else
    {
        std::cout << dist[F] << endl;
    }

    return 0;
}