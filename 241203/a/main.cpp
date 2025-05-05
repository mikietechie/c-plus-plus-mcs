#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAX_N = 1000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Используем bitset для эффективного хранения матрицы смежности
    vector<bitset<MAX_N>> adj(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        // Переводим в 0-based индексацию
        a--; b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    int triangles = 0;

    for (int u = 0; u < n; ++u) {
        for (int v = u + 1; v < n; ++v) {
            if (adj[u][v]) {
                // Находим общих соседей u и v
                bitset<MAX_N> common = adj[u] & adj[v];
                triangles += common.count();
            }
        }
    }

    // Каждый треугольник посчитан 3 раза (для каждой вершины)
    cout << triangles / 3 << endl;

    return 0;
}