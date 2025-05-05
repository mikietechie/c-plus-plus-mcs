#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> adj;
vector<int> entry, low;
vector<bool> visited;
set<int> articulation_points;
int timer = 0;

void dfs(int u, bool is_root = true) {
    visited[u] = true;
    entry[u] = low[u] = timer++;
    int children = 0;

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, false);
            low[u] = min(low[u], low[v]);
            children++;
            
            // Проверяем, является ли вершина точкой сочленения
            if (!is_root && low[v] >= entry[u]) {
                articulation_points.insert(u);
            }
        } else {
            low[u] = min(low[u], entry[v]);
        }
    }
    
    // Корень является точкой сочленения, если у него ≥2 детей
    if (is_root && children >= 2) {
        articulation_points.insert(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    adj.resize(N + 1);
    entry.resize(N + 1);
    low.resize(N + 1);
    visited.assign(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Граф связный по условию, поэтому достаточно одного DFS
    dfs(1, true);

    // Выводим результат
    cout << articulation_points.size() << '\n';
    for (int point : articulation_points) {
        cout << point << ' ';
    }
    cout << '\n';

    return 0;
}