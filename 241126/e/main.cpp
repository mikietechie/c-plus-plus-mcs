#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_stair_sum(int n, vector<int> &a)
{
    if (n == 0)
        return 0;

    vector<int> dp(n + 1, 0);
    dp[0] = 0;    // Ground level (step 0)
    dp[1] = a[0]; // First step

    for (int i = 2; i <= n; ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2]) + a[i - 1];
    }

    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    cout << max_stair_sum(n, a) << '\n';

    return 0;
}