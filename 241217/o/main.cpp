#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long count_palindromic_substrings(const string &s)
{
    int n = s.size();
    if (n < 2)
        return 0;

    // Transform string to handle even-length palindromes
    string t = "#";
    for (char c : s)
    {
        t += c;
        t += '#';
    }
    int m = t.size();

    vector<int> p(m, 0);
    int center = 0, right = 0;
    long long count = 0;

    for (int i = 1; i < m - 1; ++i)
    {
        int mirror = 2 * center - i;
        if (i < right)
        {
            p[i] = min(right - i, p[mirror]);
        }

        // Attempt to expand palindrome centered at i
        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < m &&
               t[i - p[i] - 1] == t[i + p[i] + 1])
        {
            p[i]++;
        }

        // Update center and right if palindrome expands past right
        if (i + p[i] > right)
        {
            center = i;
            right = i + p[i];
        }

        // Count palindromes (excluding single characters)
        count += (p[i] + 1) / 2;
    }

    return count - n; // Subtract single-character palindromes
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    cout << count_palindromic_substrings(s) << '\n';

    return 0;
}