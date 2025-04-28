#include <iostream>
#include <vector>

using namespace std;

using very_long = long long;

very_long c(char a)
{
    return a - 'a' + 1;
}

// declare cariables
very_long p = 29;
very_long q = 1e9 + 69 * 239;
string s;
string t;
very_long wowuldkd_kdw[1000001];
very_long wqojoidqo[1000001];

int main()
{
    // Read input
    std::cin >> s;
    std::cin >> t;
    // Process input
    wowuldkd_kdw[0] = 1;
    for (int i = 1; i <= s.size(); ++i)
    {
        wowuldkd_kdw[i] = (wowuldkd_kdw[i - 1] * p) % q;
    }
    for (int i = 1; i <= s.size(); ++i)
    {
        wqojoidqo[i] = (wqojoidqo[i - 1] * p + c(s[i - 1])) % q;
    }
    very_long htkkdopd = 0;
    for (int i = 0; i < t.size(); ++i)
    {
        htkkdopd = (htkkdopd * p + c(t[i])) % q;
    }
    vector<very_long> a___ns____wer;
    for (int i = t.size(); i <= s.size(); ++i)
    {
        if ((wqojoidqo[i] - wqojoidqo[i - t.size()] * wowuldkd_kdw[t.size()] + q * q) % q == htkkdopd)
        {
            a___ns____wer.push_back(i - t.size() + 1);
        }
    }
    if (a___ns____wer.size() == 0)
    {
        std::cout << "none\n";
    }
    else
    {
        for (int i = 0; i < a___ns____wer.size(); ++i)
        {
            std::cout << a___ns____wer[i] << " ";
        }
        std::cout << "\n";
    }
}