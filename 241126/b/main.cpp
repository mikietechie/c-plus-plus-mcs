#include <iostream>
#include <vector>

using namespace std;

long long count_ways(int n)
{
    if (n == 0)
        return 1; // Base case: empty row counts as 1 way
    if (n < 0)
        return 0; // Invalid case

    vector<long long> dp(n + 1, 0);
    dp[0] = 1; // Empty row

    for (int i = 1; i <= n; ++i)
    {
        if (i >= 2)
            dp[i] += dp[i - 2]; // Add red brick (2dm)
        if (i >= 3)
            dp[i] += dp[i - 3]; // Add blue brick (3dm)
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << count_ways(n) << endl;
    return 0;
}