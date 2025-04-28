#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> compute_z(const string &s)
{
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int find_generator_length(const string &s)
{
    int n = s.size();
    auto z = compute_z(s);
    for (int len = 1; len <= n; ++len)
    {
        if (n % len != 0)
            continue;
        bool valid = true;
        for (int i = len; i < n; i += len)
        {
            if (z[i] < min(len, n - i))
            {
                valid = false;
                break;
            }
        }
        if (valid)
            return len;
    }
    return n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string t;
    cin >> n >> t;

    int min_sum = n + 1; // Initialize with maximum possible value

    // Precompute prefix generators
    vector<int> prefix_gen(n + 1);
    string prefix;
    for (int i = 0; i < n; ++i)
    {
        prefix += t[i];
        prefix_gen[i + 1] = find_generator_length(prefix);
    }

    // Precompute suffix generators
    vector<int> suffix_gen(n + 1);
    string suffix;
    for (int i = n - 1; i >= 0; --i)
    {
        suffix = t[i] + suffix;
        suffix_gen[i] = find_generator_length(suffix);
    }

    // Find minimal sum
    for (int split = 0; split <= n; ++split)
    {
        min_sum = min(min_sum, prefix_gen[split] + suffix_gen[split]);
    }

    cout << min_sum << '\n';

    return 0;
}