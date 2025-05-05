#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, v;
    cin >> N >> M >> v;

    vector<vector<int>> adj(N + 1); // Вершины нумеруются с 1 до N
    for (int i = 0; i < M; ++i) {
        int u, w;
        cin >> u >> w;
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    // Вычисляем расстояния от начальной вершины
    vector<int> distance(N + 1, -1);
    queue<int> q;
    distance[v] = 0;
    q.push(v);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int neighbor : adj[u]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[u] + 1;
                q.push(neighbor);
            }
        }
    }

    // Собираем все вершины с их расстояниями
    vector<pair<int, int>> vertices_with_dist;
    for (int i = 1; i <= N; ++i) {
        if (distance[i] != -1) {
            vertices_with_dist.emplace_back(distance[i], i);
        }
    }

    // Сортируем вершины по расстоянию
    sort(vertices_with_dist.begin(), vertices_with_dist.end());

    // Выводим результат
    cout << vertices_with_dist.size() << '\n';
    for (size_t i = 0; i < vertices_with_dist.size(); ++i) {
        if (i != 0) cout << ' ';
        cout << vertices_with_dist[i].second;
    }
    cout << '\n';

    return 0;
}