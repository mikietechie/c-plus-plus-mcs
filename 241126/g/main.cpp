#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minimal_string_length(vector<int>& nails) {
    sort(nails.begin(), nails.end());
    int n = nails.size();
    
    vector<int> dp(n, 0);
    dp[0] = 0;  // No string needed for first nail
    dp[1] = nails[1] - nails[0];  // Must connect first two
    
    for (int i = 2; i < n; ++i) {
        // Option 1: Connect current with previous
        int option1 = dp[i-1] + (nails[i] - nails[i-1]);
        // Option 2: Connect current with i-2 (skipping i-1)
        int option2 = dp[i-2] + (nails[i] - nails[i-1]);
        dp[i] = min(option1, option2);
    }
    
    return dp[n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> nails(N);
    for (int i = 0; i < N; ++i) {
        cin >> nails[i];
    }
    
    cout << minimal_string_length(nails) << '\n';
    
    return 0;
}