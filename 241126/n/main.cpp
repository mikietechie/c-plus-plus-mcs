#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int levenshtein_distance(const string& a, const string& b) {
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Initialize base cases
    for (int i = 0; i <= m; ++i)
        dp[i][0] = i;
    for (int j = 0; j <= n; ++j)
        dp[0][j] = j;

    // Fill DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({dp[i-1][j],    // deletion
                                   dp[i][j-1],     // insertion
                                   dp[i-1][j-1]}); // substitution
            }
        }
    }

    return dp[m][n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    getline(cin, a);
    getline(cin, b);

    cout << levenshtein_distance(a, b) << '\n';

    return 0;
}