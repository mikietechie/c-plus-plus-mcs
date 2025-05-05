#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Создаем список смежности
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Массив цветов (0 - не покрашена, 1 и 2 - цвета)
    vector<int> color(n + 1, 0);
    bool is_bipartite = true;

    for (int start = 1; start <= n; ++start) {
        if (color[start] == 0) {
            queue<int> q;
            q.push(start);
            color[start] = 1;

            while (!q.empty() && is_bipartite) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == 0) {
                        color[v] = 3 - color[u]; // Альтернативный цвет
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        is_bipartite = false;
                        break;
                    }
                }
            }
        }
    }

    if (!is_bipartite) {
        cout << "-1\n";
    } else {
        for (int i = 1; i <= n; ++i) {
            if (i != 1) cout << " ";
            cout << color[i];
        }
        cout << "\n";
    }

    return 0;
}