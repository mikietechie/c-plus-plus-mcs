#include <iostream>
#include <set>
#include <string>
using namespace std;

struct Edge
{
    int u;
    int v;
};

int main(int argc, char const *argv[])
{
    int n, m, k;
    std::cin >> n >> m >> k;
    set<Edge> edges;
    for (int i; i < m; i++)
    {
        Edge e;
        std::cin >> e.u >> e.v;
        edges.insert(e);
    }
    for (int i = 0; i < k; i++)
    {
        string cmd;
        int u, v;
        std::cin >> cmd >> u >> v;
        if (cmd == "ask")
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            /* code */
            Edge e;
            for (auto _e : edges)
            {
                if ((e.u == _e.u && e.v == _e.v) || (e.u == _e.v && e.v == _e.u))
                {
                    e = _e;
                }
            }
            edges.erase(e);
        }
    }

    return 0;
}
