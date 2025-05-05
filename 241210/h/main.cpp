#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct Edge
{
    int from;
    int to;
    int weight;
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i)
    {
        std::cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    // Проверка достижимости комнаты N из комнаты 1
    vector<vector<int>> adj(N + 1);
    for (const auto &edge : edges)
    {
        adj[edge.from].push_back(edge.to);
    }

    vector<bool> reachableFrom1(N + 1, false);
    queue<int> q;
    q.push(1);
    reachableFrom1[1] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!reachableFrom1[v])
            {
                reachableFrom1[v] = true;
                q.push(v);
            }
        }
    }

    if (!reachableFrom1[N])
    {
        std::cout << "-1\n";
        return 0;
    }

    // Проверка достижимости из каждой вершины до N
    vector<vector<int>> reverseAdj(N + 1);
    for (const auto &edge : edges)
    {
        reverseAdj[edge.to].push_back(edge.from);
    }

    vector<bool> canReachN(N + 1, false);
    q.push(N);
    canReachN[N] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : reverseAdj[u])
        {
            if (!canReachN[v])
            {
                canReachN[v] = true;
                q.push(v);
            }
        }
    }

    // Алгоритм Беллмана-Форда
    vector<int> dist(N + 1, INT_MIN);
    dist[1] = 0;

    for (int i = 1; i <= N - 1; ++i)
    {
        bool updated = false;
        for (const auto &edge : edges)
        {
            int u = edge.from;
            int v = edge.to;
            int w = edge.weight;
            if (dist[u] != INT_MIN && dist[v] < dist[u] + w)
            {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }
        if (!updated)
            break;
    }

    // Проверка на положительные циклы
    bool hasPositiveCycle = false;
    for (const auto &edge : edges)
    {
        int u = edge.from;
        int v = edge.to;
        int w = edge.weight;
        if (dist[u] != INT_MIN && dist[v] < dist[u] + w && canReachN[v] && reachableFrom1[u])
        {
            hasPositiveCycle = true;
            break;
        }
    }

    if (hasPositiveCycle)
    {
        std::cout << "-1\n";
    }
    else
    {
        std::cout << dist[N] << "\n";
    }

    return 0;
}