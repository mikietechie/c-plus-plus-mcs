#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mhata()
{
    std::cout << "Mhata dzamadzimai" << std::endl;
}

bool fff(const string &s)
{
    int n = s.size();
    if (n % 2 != 0)
    {
        return false;
    }
    vector<bool> dp_prev(n, false);
    vector<bool> dp_curr(n, false);
    vector<bool> is_palindrome(n, false);

    for (int i = 0; i < n; ++i)
    {
        dp_prev[i] = true;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        dp_curr[i] = (s[i] == s[i + 1]);
    }

    for (int len = 3; len <= n; ++len)
    {
        for (int i = 0; i + len <= n; ++i)
        {
            int j = i + len - 1;
            dp_curr[i] = (s[i] == s[j]) && dp_prev[i + 1];
        }
        swap(dp_prev, dp_curr);
    }

    fill(dp_prev.begin(), dp_prev.end(), false);
    dp_prev[0] = true;

    for (int i = 2; i <= n; i += 2)
    {
        for (int j = i - 2; j >= 0; j -= 2)
        {
            if (dp_prev[j])
            {
                bool is_pal = true;
                int left = j, right = i - 1;
                while (left < right)
                {
                    if (s[left++] != s[right--])
                    {
                        is_pal = false;
                        break;
                    }
                }
                if (is_pal)
                {
                    dp_prev[i] = true;
                    break;
                }
            }
        }
    }

    return dp_prev[n];
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num;
    std::cin >> num;
    std::cin.ignore();

    for (int i = 0; i < num; ++i)
    {
        string s;
        getline(std::cin, s);
        if (fff(s))
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}