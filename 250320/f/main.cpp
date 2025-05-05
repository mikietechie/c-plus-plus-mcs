#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n;
vector<vector<int>> grid;
vector<vector<bool>> selected;
vector<vector<bool>> banned;
int max_sum = 0;

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool can_select(int x, int y) {
    if (banned[x][y]) return false;
    for (int d = 0; d < 8; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (is_valid(nx, ny)) {
            if (selected[nx][ny]) return false;
        }
    }
    return true;
}

void backtrack(int x, int y, int current_sum) {
    if (y == n) {
        y = 0;
        x++;
    }
    if (x == n) {
        if (current_sum > max_sum) {
            max_sum = current_sum;
            // Сохраняем текущее решение
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (!selected[i][j]) {
                        banned[i][j] = false;
                    }
                }
            }
        }
        return;
    }

    // Пропускаем текущую клетку
    backtrack(x, y + 1, current_sum);

    // Пробуем выбрать текущую клетку
    if (can_select(x, y)) {
        selected[x][y] = true;
        // Запрещаем соседние клетки
        for (int d = 0; d < 8; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (is_valid(nx, ny)) {
                banned[nx][ny] = true;
            }
        }
        backtrack(x, y + 1, current_sum + grid[x][y]);
        // Откатываем изменения
        selected[x][y] = false;
        for (int d = 0; d < 8; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (is_valid(nx, ny)) {
                banned[nx][ny] = false;
            }
        }
    }
}

int main() {
    cin >> n;
    grid.resize(n, vector<int>(n));
    selected.resize(n, vector<bool>(n, false));
    banned.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = row[j] - '0';
        }
    }

    if (n <= 20) {
        // Точное решение для небольших таблиц
        backtrack(0, 0, 0);
    } else {
        // Жадная эвристика для больших таблиц
        vector<pair<int, pair<int, int>>> cells;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cells.emplace_back(grid[i][j], make_pair(i, j));
            }
        }
        sort(cells.rbegin(), cells.rend());

        for (auto& cell : cells) {
            int x = cell.second.first;
            int y = cell.second.second;
            if (can_select(x, y)) {
                selected[x][y] = true;
                max_sum += cell.first;
                for (int d = 0; d < 8; ++d) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (is_valid(nx, ny)) {
                        banned[nx][ny] = true;
                    }
                }
            }
        }
    }

    // Вывод результатов
    cout << max_sum << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (selected[i][j]) {
                cout << grid[i][j];
            } else {
                cout << '0';
            }
        }
        cout << endl;
    }

    return 0;
}