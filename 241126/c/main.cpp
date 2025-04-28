#include <iostream>
#include <vector>

using namespace std;

const int MOD = 12345;

int count_sequences(int n) {
    if (n == 1) return 2;
    if (n == 2) return 4;
    
    vector<int> dp(n + 1);
    dp[0] = 1;  // Base case
    dp[1] = 2;  // 0 or 1
    dp[2] = 4;  // 00, 01, 10, 11
    
    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    }
    
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    cout << count_sequences(n) << '\n';
    
    return 0;
}