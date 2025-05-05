#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Чтение входных данных
    int N, M;
    cin >> N;
    vector<int> seq1(N);
    for (int i = 0; i < N; ++i) {
        cin >> seq1[i];
    }
    
    cin >> M;
    vector<int> seq2(M);
    for (int i = 0; i < M; ++i) {
        cin >> seq2[i];
    }
    
    // Инициализация таблицы динамического программирования
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    
    // Заполнение таблицы
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (seq1[i-1] == seq2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    // Вывод результата
    cout << dp[N][M] << endl;
    
    return 0;
}