// author mike

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point
{
    int x, y;
};

struct Edge
{
    int u, v;
    double length;
    bool operator<(const Edge &other) const
    {
        return length < other.length;
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
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    vector<Point> points(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> points[i].x >> points[i].y;
    }

    vector<Edge> edges;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            double dx = points[i].x - points[j].x;
            double dy = points[i].y - points[j].y;
            double length = sqrt(dx * dx + dy * dy);
            edges.push_back({i, j, length});
        }
    }

    sort(edges.begin(), edges.end());

    parent.resize(N);
    rank_.resize(N);
    for (int i = 0; i < N; ++i)
    {
        make_set(i);
    }

    double total_length = 0;
    vector<Edge> mst_edges;

    for (const Edge &e : edges)
    {
        if (find_set(e.u) != find_set(e.v))
        {
            total_length += e.length;
            mst_edges.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    std::cout << fixed << setprecision(6) << total_length << endl;
    std::cout << mst_edges.size() << endl;
    for (const Edge &e : mst_edges)
    {
        std::cout << e.u + 1 << " " << e.v + 1 << endl;
    }

    return 0;
}