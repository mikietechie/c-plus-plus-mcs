#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Cell {
    int jumps = INT_MAX;
    int grass = 0;
    int prev = -1;
};

int main() {
    int n;
    cin >> n;
    
    string cells;
    cin >> cells;
    
    // Проверка начальных условий
    if (cells[0] == 'w' || cells[n-1] == 'w') {
        cout << -1 << endl;
        return 0;
    }
    
    vector<Cell> dp(n);
    dp[0].jumps = 0;
    dp[0].grass = 0;
    
    queue<int> q;
    q.push(0);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        // Проверяем все возможные прыжки
        for (int step : {2, 3, 6}) {
            int next = current + step;
            
            // Проверяем границы и болота
            if (next >= n || cells[next] == 'w') continue;
            
            int new_grass = dp[current].grass + (cells[next] == '*' ? 1 : 0);
            
            // Если нашли более короткий путь
            if (dp[next].jumps > dp[current].jumps + 1) {
                dp[next].jumps = dp[current].jumps + 1;
                dp[next].grass = new_grass;
                dp[next].prev = current;
                q.push(next);
            }
            // Если путь такой же длины, но с большим количеством травы
            else if (dp[next].jumps == dp[current].jumps + 1 && dp[next].grass < new_grass) {
                dp[next].grass = new_grass;
                dp[next].prev = current;
            }
        }
    }
    
    // Проверка достижимости последней клетки
    if (dp[n-1].jumps == INT_MAX) {
        cout << -1 << endl;
        return 0;
    }
    
    // Вывод результатов
    cout << dp[n-1].jumps << " " << dp[n-1].grass << endl;
    
    // Восстановление пути
    vector<int> path;
    for (int i = n-1; i != -1; i = dp[i].prev) {
        path.push_back(i+1); // +1 для перехода к 1-индексации
    }
    reverse(path.begin(), path.end());
    
    for (int cell : path) {
        cout << cell << " ";
    }
    cout << endl;
    
    return 0;
}