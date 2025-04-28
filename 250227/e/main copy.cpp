#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <cassert>
#include <istream>
#include <numeric>
#include <random>
#include <complex>

#define ld long double
#define ll long long
#define int long long
#define x first
#define y second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define pii pair<int, int>
using namespace std;

const double PI = acos(-1);

void fft(vector<complex<double>> &a, bool inv)
{
    int n = sz(a);
    if (n <= 1)
        return;

    for (int i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
        {
            j ^= bit;
        }
        j ^= bit;
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }

    for (int len = 2; len <= n; len <<= 1)
    {
        double angle = 2 * PI / len;
        if (inv)
        {
            angle *= -1;
        }
        complex<double> root(cos(angle), sin(angle));
        for (int i = 0; i < n; i += len)
        {
            complex<double> w(1);
            for (int j = 0; j < len / 2; j++)
            {
                complex<double> u = a[i + j];
                complex<double> v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= root;
            }
        }
    }

    if (inv)
    {
        for (auto &x : a)
            x /= n;
    }
}

string multiply(const string &num1, const string &num2)
{
    if (num1 == "0" || num2 == "0")
        return "0";

    vector<int> n1(num1.size()), n2(num2.size());
    for (int i = 0; i < num1.size(); i++)
        n1[i] = num1[num1.size() - 1 - i] - '0';
    for (int i = 0; i < num2.size(); i++)
        n2[i] = num2[num2.size() - 1 - i] - '0';

    int size = 1;
    while (size < n1.size() + n2.size())
        size <<= 1;

    vector<complex<double>> a(size), b(size);
    copy(all(n1), a.begin());
    copy(all(n2), b.begin());

    fft(a, false);
    fft(b, false);

    for (int i = 0; i < size; i++)
        a[i] *= b[i];

    fft(a, true);

    vector<int> result(size);
    for (int i = 0; i < size; i++)
        result[i] = round(a[i].real());

    int carry = 0;
    for (int i = 0; i < size; i++)
    {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }

    string res;
    bool leading_zero = true;
    for (int i = size - 1; i >= 0; i--)
    {
        if (result[i] != 0)
            leading_zero = false;
        if (!leading_zero)
            res += to_string(result[i]);
    }
    if (res.empty())
    {
        return "0";
    }
    else
    {
        return res;
    }
}

signed main()
{
    string num1, num2;
    cin >> num1;
    cin >> num2;
    int f = 0;
    if (num1[0] == '-')
    {
        f ^= 1;
        num1 = num1.substr(1, sz(num1) - 1);
    }
    if (num2[0] == '-')
    {
        f ^= 1;
        num2 = num2.substr(1, sz(num2) - 1);
    }

    string result = multiply(num1, num2);
    if (f && result != "0")
    {
        cout << "-";
    }
    cout << result;
}