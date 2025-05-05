#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Чтение трех последовательностей
    vector<vector<int>> seqs(3);
    vector<int> lens(3);
    
    for (int i = 0; i < 3; ++i) {
        cin >> lens[i];
        seqs[i].resize(lens[i]);
        for (int j = 0; j < lens[i]; ++j) {
            cin >> seqs[i][j];
        }
    }
    
    // Инициализация трехмерной таблицы DP
    vector<vector<vector<int>>> dp(
        lens[0] + 1, 
        vector<vector<int>>(
            lens[1] + 1, 
            vector<int>(lens[2] + 1, 0)
        )
    );
    
    // Заполнение таблицы DP
    for (int i = 1; i <= lens[0]; ++i) {
        for (int j = 1; j <= lens[1]; ++j) {
            for (int k = 1; k <= lens[2]; ++k) {
                if (seqs[0][i-1] == seqs[1][j-1] && seqs[1][j-1] == seqs[2][k-1]) {
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                } else {
                    dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
                }
            }
        }
    }
    
    // Вывод длины НОП
    int result = dp[lens[0]][lens[1]][lens[2]];
    cout << result << endl;
    
    // Восстановление самой подпоследовательности
    if (result > 0) {
        vector<int> lcs;
        int i = lens[0], j = lens[1], k = lens[2];
        
        while (i > 0 && j > 0 && k > 0) {
            if (seqs[0][i-1] == seqs[1][j-1] && seqs[1][j-1] == seqs[2][k-1]) {
                lcs.push_back(seqs[0][i-1]);
                i--; j--; k--;
            } else {
                if (dp[i][j][k] == dp[i-1][j][k]) {
                    i--;
                } else if (dp[i][j][k] == dp[i][j-1][k]) {
                    j--;
                } else {
                    k--;
                }
            }
        }
        
        // Вывод подпоследовательности в правильном порядке
        reverse(lcs.begin(), lcs.end());
        for (int num : lcs) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}