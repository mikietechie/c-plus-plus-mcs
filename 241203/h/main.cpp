#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 101;

// Возможные направления ходов (p,q)-лошади
vector<pair<int, int>> get_moves(int p, int q) {
    vector<pair<int, int>> moves;
    int directions[8][2] = {{p, q}, {p, -q}, {-p, q}, {-p, -q},
                            {q, p}, {q, -p}, {-q, p}, {-q, -p}};
    for (auto [dx, dy] : directions) {
        moves.emplace_back(dx, dy);
    }
    return moves;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, p, q, x1, y1, x2, y2;
    cin >> M >> N >> p >> q >> x1 >> y1 >> x2 >> y2;

    // Переводим в 0-based индексацию для удобства
    x1--; y1--; x2--; y2--;

    // Получаем все возможные ходы
    auto moves = get_moves(p, q);

    // Матрицы для расстояний и предыдущих клеток
    vector<vector<int>> dist(M, vector<int>(N, -1));
    vector<vector<pair<int, int>>> prev(M, vector<pair<int, int>>(N, {-1, -1}));

    queue<pair<int, int>> q_bfs;
    q_bfs.push({x1, y1});
    dist[x1][y1] = 0;

    bool found = false;
    while (!q_bfs.empty() && !found) {
        auto [x, y] = q_bfs.front();
        q_bfs.pop();

        for (auto [dx, dy] : moves) {
            int nx = x + dx;
            int ny = y + dy;

            // Проверяем границы доски
            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    prev[nx][ny] = {x, y};
                    q_bfs.push({nx, ny});

                    // Если достигли цели
                    if (nx == x2 && ny == y2) {
                        found = true;
                        break;
                    }
                }
            }
        }
    }

    if (dist[x2][y2] == -1) {
        cout << -1 << '\n';
        return 0;
    }

    // Восстанавливаем путь
    vector<pair<int, int>> path;
    int x = x2, y = y2;
    while (x != -1 && y != -1) {
        path.emplace_back(x, y);
        auto [px, py] = prev[x][y];
        x = px;
        y = py;
    }
    reverse(path.begin(), path.end());

    // Выводим результат
    cout << path.size() - 1 << '\n';
    for (auto [x, y] : path) {
        cout << x + 1 << ' ' << y + 1 << '\n'; // Переводим обратно в 1-based
    }

    return 0;
}