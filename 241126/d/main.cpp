#include <iostream>
#include <vector>

using namespace std;

long long count_valid_strings(int n) {
    if (n == 0) return 1;
    
    // dp[i][last_char] where last_char: 0=a, 1=b, 2=c
    vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
    
    // Base cases for strings of length 1
    dp[1][0] = 1; // "a"
    dp[1][1] = 1; // "b"
    dp[1][2] = 1; // "c"
    
    for (int i = 2; i <= n; ++i) {
        // Can append 'a' after any character except 'b' (to avoid "ba" becoming "ba" is okay)
        dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
        
        // Can append 'b' after any character except 'a' (to avoid "ab")
        dp[i][1] = dp[i-1][1] + dp[i-1][2];
        
        // Can append 'c' after any character
        dp[i][2] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
    }
    
    return dp[n][0] + dp[n][1] + dp[n][2];
}

int main() {
    int n;
    cin >> n;
    cout << count_valid_strings(n) << endl;
    return 0;
}