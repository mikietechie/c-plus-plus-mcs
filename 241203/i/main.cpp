#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj; // Список смежности
vector<bool> visited;
vector<int> path;

void dfs(int u) {
    visited[u] = true;
    path.push_back(u);
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
            path.push_back(u); // Возвращаемся к родителю
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, v;
    cin >> N >> M >> v;

    adj.resize(N + 1);
    visited.assign(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int u, w;
        cin >> u >> w;
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    // Запускаем DFS из начальной вершины
    dfs(v);

    // Выводим результат
    cout << path.size() << '\n';
    for (size_t i = 0; i < path.size(); ++i) {
        if (i != 0) cout << ' ';
        cout << path[i];
    }
    cout << '\n';

    return 0;
}