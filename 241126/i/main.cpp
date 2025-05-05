#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
    
    vector<int> dp(n, -1);
    dp[0] = 0;
    
    for (int k = 1; k < n; ++k) {
        if (cells[k] == 'w') continue;
        
        int max_prev = -1;
        // Проверяем все возможные предыдущие шаги
        for (int step : {1, 3, 5}) {
            if (k - step >= 0 && dp[k-step] != -1) {
                max_prev = max(max_prev, dp[k-step]);
            }
        }
        
        if (max_prev != -1) {
            dp[k] = max_prev + (cells[k] == '"' ? 1 : 0);
        }
    }
    
    cout << dp[n-1] << endl;
    
    return 0;
}