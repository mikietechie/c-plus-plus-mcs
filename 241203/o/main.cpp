#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;
    cin.ignore(); // Пропускаем перевод строки после чисел

    vector<vector<char>> grid(r, vector<char>(c));
    queue<pair<int, int>> moss_cells;

    // Чтение входных данных и начальное заполнение мхом
    for (int i = 0; i < r; ++i) {
        string line;
        getline(cin, line);
        for (int j = 0; j < c; ++j) {
            grid[i][j] = line[j];
            if (grid[i][j] == '*') {
                moss_cells.push({i, j});
            }
        }
    }

    int days = 0;
    bool changed;

    do {
        changed = false;
        vector<pair<int, int>> new_moss;
        
        // Проверяем все свободные клетки
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == '.') {
                    int moss_neighbors = 0;
                    
                    // Проверяем всех 8 соседей
                    for (int d = 0; d < 8; ++d) {
                        int ni = i + dx[d];
                        int nj = j + dy[d];
                        
                        if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                            if (grid[ni][nj] == '*') {
                                moss_neighbors++;
                            }
                        }
                    }
                    
                    // Если соседей с мхом ≥ 2, клетка покроется мхом
                    if (moss_neighbors >= 2) {
                        new_moss.emplace_back(i, j);
                    }
                }
            }
        }
        
        // Обновляем карту
        if (!new_moss.empty()) {
            changed = true;
            days++;
            for (auto [i, j] : new_moss) {
                grid[i][j] = '*';
            }
        }
        
    } while (changed);

    cout << days << '\n';

    return 0;
}