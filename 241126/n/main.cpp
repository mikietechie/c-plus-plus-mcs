#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int n = s1.length();
    int m = s2.length();

    // Инициализация таблицы DP
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Базовые случаи
    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; ++j)
    {
        dp[0][j] = j;
    }

    // Заполнение таблицы
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i - 1][j],       // удаление
                                    dp[i][j - 1],       // вставка
                                    dp[i - 1][j - 1]}); // замена
            }
        }
    }

    // Вывод результата
    cout << dp[n][m] << endl;

    return 0;
}