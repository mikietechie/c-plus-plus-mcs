// author mike

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, weight;
    bool operator<(Edge const &other) const
    {
        return weight < other.weight;
    }
};

vector<int> parent, rank_;

void make_set(int v)
{
    parent[v] = v;
    rank_[v] = 0;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (rank_[a] < rank_[b])
            swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b])
            rank_[a]++;
    }
}

int main()
{

    int n, m;
    std::cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--;
        edges[i].v--;
    }

    sort(edges.begin(), edges.end());

    parent.resize(n);
    rank_.resize(n);
    for (int i = 0; i < n; ++i)
        make_set(i);

    int total_weight = 0;
    int edges_used = 0;

    for (Edge e : edges)
    {
        if (find_set(e.u) != find_set(e.v))
        {
            total_weight += e.weight;
            union_sets(e.u, e.v);
            edges_used++;
            if (edges_used == n - 1)
                break;
        }
    }

    if (edges_used == n - 1)
    {
        std::cout << total_weight << endl;
    }
    else
    {
        std::cout << "Impossible" << endl;
    }

    return 0;
}