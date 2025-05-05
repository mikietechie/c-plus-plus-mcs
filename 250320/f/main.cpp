#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = row[j] - '0';
        }
    }
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) continue;
            int up = (i > 0) ? dp[i-1][j] : 0;
            int left = (j > 0) ? dp[i][j-1] : 0;
            dp[i][j] = max(up, left);
            if ((i == 0 || dp[i-1][j] == 0) && (j == 0 || dp[i][j-1] == 0)) {
                dp[i][j] = grid[i][j];
            }
        }
    }
    
    cout << dp[n-1][n-1] << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (dp[i][j] == grid[i][j] ? grid[i][j] : 0);
        }
        cout << endl;
    }
    
    return 0;
}