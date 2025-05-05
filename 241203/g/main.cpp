#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, z;
    cin >> x >> y >> z;
    cin.ignore(); // Пропускаем перевод строки после чисел

    // Трехмерный массив для хранения кубиков
    vector<vector<vector<char>>> cube(z, vector<vector<char>>(y, vector<char>(x)));

    // Чтение входных данных
    for (int layer = 0; layer < z; ++layer) {
        // Пропускаем пустую строку перед слоем
        string empty_line;
        getline(cin, empty_line);
        
        for (int row = 0; row < y; ++row) {
            string line;
            getline(cin, line);
            for (int col = 0; col < x; ++col) {
                cube[layer][row][col] = line[col];
            }
        }
    }

    // Массив для отметки посещенных кубиков
    vector<vector<vector<bool>>> visited(z, vector<vector<bool>>(y, vector<bool>(x, false)));
    int components = 0;

    for (int k = 0; k < z; ++k) {
        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                if (!visited[k][i][j]) {
                    components++;
                    char current_block = cube[k][i][j];
                    queue<tuple<int, int, int>> q;
                    q.push({k, i, j});
                    visited[k][i][j] = true;

                    while (!q.empty()) {
                        auto [cz, cy, cx] = q.front();
                        q.pop();

                        // Проверяем всех 6 соседей
                        for (int d = 0; d < 6; ++d) {
                            int nz = cz + dz[d];
                            int ny = cy + dy[d];
                            int nx = cx + dx[d];

                            // Проверка границ
                            if (nz >= 0 && nz < z && ny >= 0 && ny < y && nx >= 0 && nx < x) {
                                // Если соседний кубик того же блока и не посещен
                                if (!visited[nz][ny][nx] && cube[nz][ny][nx] == current_block) {
                                    visited[nz][ny][nx] = true;
                                    q.push({nz, ny, nx});
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << components << '\n';

    return 0;
}