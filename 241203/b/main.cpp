#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // Создаем список смежности
    vector<vector<int>> adj(N + 1); // Вершины нумеруются с 1 до N

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Граф неориентированный
    }

    vector<bool> visited(N + 1, false);
    stack<int> s;

    // Начинаем обход с вершины 1
    if (N > 0) {
        s.push(1);
        visited[1] = true;
    }

    int count = 0;

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        count++;

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                s.push(v);
            }
        }
    }

    // Граф связный, если мы посетили все вершины
    if (count == N) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}