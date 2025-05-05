#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int longestCommonSubstr(const vector<string> &strings)
{
    if (strings.empty())
        return 0;

    // Find the shortest string to minimize comparisons
    const string &shortest = *min_element(strings.begin(), strings.end(),
                                          [](const string &a, const string &b)
                                          { return a.length() < b.length(); });

    int max_len = 0;

    // Try all possible substrings of the shortest string
    for (int i = 0; i < shortest.length(); i++)
    {
        for (int j = i + 1; j <= shortest.length(); j++)
        {
            string candidate = shortest.substr(i, j - i);

            bool common_to_all = true;
            for (const string &s : strings)
            {
                if (s.find(candidate) == string::npos)
                {
                    common_to_all = false;
                    break;
                }
            }

            if (common_to_all && candidate.length() > max_len)
            {
                max_len = candidate.length();
            }
        }
    }

    return max_len;
}

// Optimized version using dynamic programming for N strings
string longestCommonSubstrDP(const vector<string> &strings)
{
    if (strings.empty())
        return 0;

    // Use first string as reference
    const string &ref = strings[0];
    int m = ref.length();
    int max_len = 0;
    string ans = "";

    // For each possible starting position in reference string
    for (int i = 0; i < m; i++)
    {
        // For each possible length starting at i
        for (int len = 1; len <= m - i; len++)
        {
            string candidate = ref.substr(i, len);

            // Check if this substring exists in all other strings
            bool common = true;
            for (size_t k = 1; k < strings.size(); k++)
            {
                if (strings[k].find(candidate) == string::npos)
                {
                    common = false;
                    break;
                }
            }

            if (common && len > max_len)
            {
                max_len = len;
                ans = candidate;
            }
            else if (!common)
            {
                // No point checking longer substrings if shorter one doesn't exist
                break;
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> strings;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        strings.push_back(str);
    }
    cout << longestCommonSubstrDP(strings) << endl;

    return 0;
}