#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isTree(int n, const vector<vector<int>>& adj) {
    // Дерево должно иметь ровно n-1 ребер
    int edgeCount = 0;
    for (const auto& neighbors : adj) {
        edgeCount += neighbors.size();
    }
    edgeCount /= 2; // Каждое ребро посчитано дважды
    
    if (edgeCount != n - 1) {
        return false;
    }

    // Проверка связности с помощью DFS
    vector<bool> visited(n + 1, false);
    stack<int> s;
    int count = 0;

    if (n > 0) {
        s.push(1);
        visited[1] = true;
    }

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

    return count == n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1); // Вершины нумеруются с 1 до n

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isTree(n, adj)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}