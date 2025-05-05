#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isMatch(const string &s, const string &p) {
    int m = s.length(), n = p.length();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    
    // Пустая строка соответствует пустому шаблону
    dp[0][0] = true;
    
    // Обработка шаблонов, начинающихся с '*'
    for (int j = 1; j <= n; ++j) {
        if (p[j-1] == '*') {
            dp[0][j] = dp[0][j-1];
        }
    }
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j-1] == '*') {
                // '*' может соответствовать:
                // 1. Пустой последовательности (dp[i][j-1])
                // 2. Одному или более символам (dp[i-1][j])
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
            else if (p[j-1] == '?' || s[i-1] == p[j-1]) {
                // '?' соответствует любому символу
                // Или символы совпадают
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string pattern, str;
    getline(cin, pattern);
    getline(cin, str);
    
    if (isMatch(str, pattern)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}