#include <iostream>
#include <cmath>

using namespace std;

int64_t calculate_r(int64_t n)
{
    int64_t r = 0;
    int64_t k = sqrt(n);

    // Handle the case where i <= sqrt(n)
    for (int64_t i = 1; i <= k; ++i)
    {
        r += n / i;
    }

    // Handle the case where i > sqrt(n)
    // For each possible value v of n/i, count how many i's produce this value
    for (int64_t v = 1; v <= n / (k + 1); ++v)
    {
        int64_t lower = n / (v + 1) + 1;
        int64_t upper = n / v;
        r += v * (upper - lower + 1);
    }

    return r;
}

int64_t func(int64_t n)
{
    int64_t r = 0;
    for (int64_t i = 1; i <= n; i++)
    {
        for (int64_t j = 1; j <= n; j += i)
        {
            r += 1;
        }
    }

    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n;
    cin >> n;
    cout << calculate_r(n) << '\n';

    return 0;
}