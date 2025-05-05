#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj; // Смежные вершины и номера ребер
vector<int> entry, low;
vector<bool> visited;
vector<int> bridges;
int timer = 0;

void dfs(int u, int parent_edge = -1) {
    visited[u] = true;
    entry[u] = low[u] = timer++;
    
    for (auto [v, edge_idx] : adj[u]) {
        if (edge_idx == parent_edge) continue; // Пропускаем ребро к родителю
        
        if (visited[v]) {
            // Обратное ребро - часть цикла
            low[u] = min(low[u], entry[v]);
        } else {
            dfs(v, edge_idx);
            low[u] = min(low[u], low[v]);
            
            // Проверяем, является ли ребро мостом
            if (low[v] > entry[u]) {
                bridges.push_back(edge_idx);
            }
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

    // Читаем ребра и сохраняем их индексы
    for (int i = 1; i <= m; ++i) {
        int b, c;
        cin >> b >> c;
        adj[b].emplace_back(c, i);
        adj[c].emplace_back(b, i);
    }

    // Запускаем DFS для всех компонент связности
    for (int u = 1; u <= n; ++u) {
        if (!visited[u]) {
            dfs(u);
        }
    }

    // Сортируем мосты по возрастанию номеров
    sort(bridges.begin(), bridges.end());

    // Выводим результат
    cout << bridges.size() << '\n';
    for (int i = 0; i < bridges.size(); ++i) {
        if (i != 0) cout << ' ';
        cout << bridges[i];
    }
    cout << '\n';

    return 0;
}