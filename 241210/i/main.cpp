#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = 10000;

struct Edge
{
    int from;
    int to;
    int weight;
};

void findNegativeCycle(int X, const vector<vector<int>> &graph)
{
    vector<Edge> edges;
    for (int i = 0; i < X; ++i)
    {
        for (int j = 0; j < X; ++j)
        {
            if (graph[i][j] != INF)
            {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    vector<int> dist(X, 0);
    vector<int> parent(X, -1);
    int lastUpdatedVertex = -1;

    for (int i = 0; i < X; ++i)
    {
        lastUpdatedVertex = -1;
        for (const auto &edge : edges)
        {
            if (dist[edge.from] + edge.weight < dist[edge.to])
            {
                dist[edge.to] = dist[edge.from] + edge.weight;
                parent[edge.to] = edge.from;
                lastUpdatedVertex = edge.to;
            }
        }
    }

    if (lastUpdatedVertex == -1)
    {
        std::cout << "NO" << endl;
        return;
    }

    // Восстановление цикла
    for (int i = 0; i < X; ++i)
    {
        lastUpdatedVertex = parent[lastUpdatedVertex];
    }

    vector<int> cycle;
    int current = lastUpdatedVertex;
    while (true)
    {
        cycle.push_back(current);
        if (current == lastUpdatedVertex && cycle.size() > 1)
        {
            break;
        }
        current = parent[current];
    }

    reverse(cycle.begin(), cycle.end());

    std::cout << "YES" << endl;
    std::cout << cycle.size() - 1 << endl;
    for (int i = 0; i < cycle.size() - 1; ++i)
    {
        if (i != 0)
        {
            std::cout << " ";
        }
        std::cout << cycle[i] + 1; // Вершины нумеруются с 1
    }
    std::cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int X;
    std::cin >> X;

    vector<vector<int>> graph(X, vector<int>(X));
    for (int i = 0; i < X; ++i)
    {
        for (int j = 0; j < X; ++j)
        {
            std::cin >> graph[i][j];
        }
    }

    findNegativeCycle(X, graph);

    return 0;
}