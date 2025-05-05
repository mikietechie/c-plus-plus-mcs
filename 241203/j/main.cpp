#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<int> order;
bool has_cycle = false;

void dfs(int u) {
    visited[u] = 1; // Помечаем как посещенную
    
    for (int v : adj[u]) {
        if (visited[v] == 1) {
            // Обнаружен цикл
            has_cycle = true;
            return;
        }
        if (visited[v] == 0) {
            dfs(v);
        }
    }
    
    visited[u] = 2; // Помечаем как полностью обработанную
    order.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    adj.resize(N + 1);
    visited.assign(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Выполняем DFS для всех непосещенных вершин
    for (int u = 1; u <= N; ++u) {
        if (visited[u] == 0) {
            dfs(u);
            if (has_cycle) {
                break;
            }
        }
    }

    if (has_cycle) {
        cout << -1 << '\n';
    } else {
        // Выводим вершины в обратном порядке (по времени выхода)
        reverse(order.begin(), order.end());
        for (size_t i = 0; i < order.size(); ++i) {
            if (i != 0) cout << ' ';
            cout << order[i];
        }
        cout << '\n';
    }

    return 0;
}