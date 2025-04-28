#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int m, n, g, t;
    cin >> m >> n >> g >> t;
    vector<vector<int>> grid(m + 1, vector<int>(n + 1, 0)); // 0: empty, 1: mushroom, -1: tree
    // Read mushroom positions
    for (int i = 0; i < g; ++i)
    {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1; // Mark mushroom
    }
    // Read tree positions
    for (int i = 0; i < t; ++i)
    {
        int x, y;
        cin >> x >> y;
        grid[x][y] = -1; // Mark tree
    }
    // DP table to store maximum mushrooms collected
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    vector<vector<pair<int, int>>> path(m + 1, vector<pair<int, int>>(n + 1));
    dp[1][1] = 0; // Starting point
    // Fill the DP table
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (grid[i][j] == -1)
                continue; // Skip trees
            if (i > 1 && dp[i - 1][j] != -1)
            { // Coming from above
                int mushrooms = dp[i - 1][j] + (grid[i][j] == 1 ? 1 : 0);
                if (mushrooms > dp[i][j])
                {
                    dp[i][j] = mushrooms;
                    path[i][j] = {i - 1, j}; // Store path
                }
            }
            if (j > 1 && dp[i][j - 1] != -1)
            { // Coming from the left
                int mushrooms = dp[i][j - 1] + (grid[i][j] == 1 ? 1 : 0);
                if (mushrooms > dp[i][j])
                {
                    dp[i][j] = mushrooms;
                    path[i][j] = {i, j - 1}; // Store path
                }
            }
        }
    }
    // Check if we can reach the bottom-right corner
    if (dp[m][n] == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    // Output the maximum mushrooms collected
    cout << dp[m][n] << endl;
    // Reconstruct the path
    vector<pair<int, int>> result;
    int x = m, y = n;
    while (x != 1 || y != 1)
    {
        result.push_back({x, y});
        auto prev = path[x][y];
        x = prev.first;
        y = prev.second;
    }
    result.push_back({1, 1});
    reverse(result.begin(), result.end());
    // Output the path
    for (const auto &p : result)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}