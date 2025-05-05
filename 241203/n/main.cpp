#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<pair<int, int>>> adj; // Смежные вершины и номера ребер
vector<int> entry, low;
vector<bool> visited;
vector<bool> is_bridge;
vector<int> parent;
int timer = 0;

void dfs_bridges(int u) {
    visited[u] = true;
    entry[u] = low[u] = timer++;
    
    for (auto [v, edge_idx] : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs_bridges(v);
            low[u] = min(low[u], low[v]);
            
            if (low[v] > entry[u]) {
                is_bridge[edge_idx] = true;
            }
        } else if (v != parent[u]) {
            low[u] = min(low[u], entry[v]);
        }
    }
}

vector<bool> on_path;
vector<int> path_count;

void dfs_paths(int u, int target) {
    visited[u] = true;
    if (u == target) {
        on_path[u] = true;
        return;
    }
    
    for (auto [v, edge_idx] : adj[u]) {
        if (!visited[v]) {
            dfs_paths(v, target);
            if (on_path[v]) {
                on_path[u] = true;
                path_count[edge_idx]++;
            }
        } else if (on_path[v]) {
            path_count[edge_idx]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    entry.resize(n + 1);
    low.resize(n + 1);
    visited.assign(n + 1, false);
    is_bridge.assign(m + 1, false);
    parent.resize(n + 1, -1);

    // Читаем ребра и сохраняем их индексы
    for (int i = 1; i <= m; ++i) {
        int b, c;
        cin >> b >> c;
        adj[b].emplace_back(c, i);
        adj[c].emplace_back(b, i);
    }

    // Находим все мосты в графе
    dfs_bridges(1);

    // Проверяем, какие мосты лежат на всех путях между 1 и n
    on_path.assign(n + 1, false);
    path_count.assign(m + 1, 0);
    visited.assign(n + 1, false);
    dfs_paths(1, n);

    // Собираем неизбежные ребра (мосты, лежащие на всех путях)
    vector<int> inevitable_edges;
    for (int i = 1; i <= m; ++i) {
        if (is_bridge[i] && path_count[i] > 0) {
            inevitable_edges.push_back(i);
        }
    }

    // Сортируем результат
    sort(inevitable_edges.begin(), inevitable_edges.end());

    // Выводим результат
    cout << inevitable_edges.size() << '\n';
    for (int i = 0; i < inevitable_edges.size(); ++i) {
        if (i != 0) cout << ' ';
        cout << inevitable_edges[i];
    }
    cout << '\n';

    return 0;
}