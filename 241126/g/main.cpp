#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> nails(N);
    for (int i = 0; i < N; ++i) {
        cin >> nails[i];
    }
    
    // Сортируем координаты гвоздиков
    sort(nails.begin(), nails.end());
    
    // Инициализация массива динамического программирования
    vector<int> dp(N, INT_MAX);
    
    // Базовые случаи
    dp[0] = 0;
    dp[1] = nails[1] - nails[0];
    
    if (N > 2) {
        dp[2] = nails[2] - nails[0];
    }
    
    // Заполнение массива DP
    for (int i = 3; i < N; ++i) {
        dp[i] = min(dp[i-1] + (nails[i] - nails[i-1]), 
                    dp[i-2] + (nails[i] - nails[i-1]));
    }
    
    cout << dp[N-1] << endl;
    
    return 0;
}