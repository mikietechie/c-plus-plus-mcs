#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Создаем список смежности
    vector<vector<int>> adj(n + 1); // Вершины нумеруются с 1 до n

    for (int i = 2; i <= n; ++i) {
        int parent;
        cin >> parent;
        adj[parent].push_back(i);
        adj[i].push_back(parent); // Дерево неориентированное
    }

    vector<int> distance(n + 1, -1);
    queue<int> q;

    // Начинаем обход с корня (вершины 1)
    distance[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }

    // Находим максимальное расстояние
    int max_dist = *max_element(distance.begin() + 1, distance.end());

    // Собираем вершины с максимальным расстоянием
    vector<int> farthest_vertices;
    for (int i = 1; i <= n; ++i) {
        if (distance[i] == max_dist) {
            farthest_vertices.push_back(i);
        }
    }

    // Сортируем вершины по возрастанию
    sort(farthest_vertices.begin(), farthest_vertices.end());

    // Выводим результаты
    cout << max_dist << '\n';
    cout << farthest_vertices.size() << '\n';
    for (size_t i = 0; i < farthest_vertices.size(); ++i) {
        if (i != 0) cout << ' ';
        cout << farthest_vertices[i];
    }
    cout << '\n';

    return 0;
}