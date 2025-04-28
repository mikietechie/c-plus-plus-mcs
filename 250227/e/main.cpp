// #include <iostream>
// #include <sstream>
// #include <algorithm>
// #include <vector>
// #include <cmath>
// #include <iomanip>
// #include <string>
// #include <queue>
// #include <deque>
// #include <bitset>
// #include <cassert>
// #include <istream>
// #include <numeric>
// #include <random>
// #include <complex>

// #define ld long double
// #define ll long long
// #define int long long
// #define x first
// #define y second
// #define all(x) x.begin(), x.end()
// #define sz(x) (int)(x.size())
// #define pii pair<int, int>
// using namespace std;

// const double PI = acos(-1);

// void fft(vector<complex<double>> &a, bool inv)
// {
//     int n = sz(a);
//     if (n <= 1)
//         return;

//     for (int i = 1, j = 0; i < n; i++)
//     {
//         int bit = n >> 1;
//         for (; j & bit; bit >>= 1)
//         {
//             j ^= bit;
//         }
//         j ^= bit;
//         if (i < j)
//         {
//             swap(a[i], a[j]);
//         }
//     }

//     for (int len = 2; len <= n; len <<= 1)
//     {
//         double angle = 2 * PI / len;
//         if (inv)
//         {
//             angle *= -1;
//         }
//         complex<double> root(cos(angle), sin(angle));
//         for (int i = 0; i < n; i += len)
//         {
//             complex<double> w(1);
//             for (int j = 0; j < len / 2; j++)
//             {
//                 complex<double> u = a[i + j];
//                 complex<double> v = a[i + j + len / 2] * w;
//                 a[i + j] = u + v;
//                 a[i + j + len / 2] = u - v;
//                 w *= root;
//             }
//         }
//     }

//     if (inv)
//     {
//         for (auto &x : a)
//             x /= n;
//     }
// }

// string multiply(const string &number_1, const string &number_2)
// {
//     if (number_1 == "0" || number_2 == "0")
//         return "0";

//     vector<int> n1(number_1.size()), n2(number_2.size());
//     for (int i = 0; i < number_1.size(); i++)
//         n1[i] = number_1[number_1.size() - 1 - i] - '0';
//     for (int i = 0; i < number_2.size(); i++)
//         n2[i] = number_2[number_2.size() - 1 - i] - '0';

//     int size = 1;
//     while (size < n1.size() + n2.size())
//         size <<= 1;

//     vector<complex<double>> a(size), b(size);
//     copy(all(n1), a.begin());
//     copy(all(n2), b.begin());

//     fft(a, false);
//     fft(b, false);

//     for (int i = 0; i < size; i++)
//         a[i] *= b[i];

//     fft(a, true);

//     vector<int> result(size);
//     for (int i = 0; i < size; i++)
//         result[i] = round(a[i].real());

//     int carry = 0;
//     for (int i = 0; i < size; i++)
//     {
//         result[i] += carry;
//         carry = result[i] / 10;
//         result[i] %= 10;
//     }

//     string res;
//     bool leading_zero = true;
//     for (int i = size - 1; i >= 0; i--)
//     {
//         if (result[i] != 0)
//             leading_zero = false;
//         if (!leading_zero)
//             res += to_string(result[i]);
//     }
//     if (res.empty())
//     {
//         return "0";
//     }
//     else
//     {
//         return res;
//     }
// }

// int multiply_mike()
// {
//     /*
//     Hello, it's me
//     I was wondering if after all these years you'd like to meet
//     To go over everything
//     They say that time's supposed to heal ya, but I ain't done much healing
//     Hello, can you hear me?
//     I'm in California dreaming about who we used to be
//     When we were younger and free
//     I've forgotten how it felt before the world fell at our feet
//     There's such a difference between us
//     And a million miles
//     */
//     std::cout << "/* message */" << std::endl;
// }

// signed main()
// {
//     string number_1, number_2;
//     std::cin >> number_1;
//     std::cin >> number_2;
//     int negative = 0;
//     if (number_1[0] == '-')
//     {
//         // check if number 1 is negative
//         negative ^= 1;
//         number_1 = number_1.substr(1, sz(number_1) - 1);
//     }
//     if (number_2[0] == '-')
//     {
//         // check if number 1 is negative
//         negative ^= 1;
//         number_2 = number_2.substr(1, sz(number_2) - 1);
//     }
//     string result = multiply(number_1, number_2);
//     if (negative && result != "0")
//     {
//         std::cout << "-";
//     }
//     std::cout << result << "\n";
// }

#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>

using namespace std;

using cd = complex<double>;
const double PI = acos(-1);

// In-place iterative FFT
void fft(vector<cd> &a, bool invert) {
    int n = a.size();
    
    // Bit-reversal permutation
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j)
            swap(a[i], a[j]);
    }

    // Danielson-Lanczos
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));

        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; ++j) {
                cd u = a[i + j];
                cd v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd &x : a)
            x /= n;
    }
}

// Multiply two large numbers represented as strings
string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
        return "0";

    bool negative = false;
    if (num1[0] == '-') {
        negative = !negative;
        num1 = num1.substr(1);
    }
    if (num2[0] == '-') {
        negative = !negative;
        num2 = num2.substr(1);
    }

    int n1 = num1.size(), n2 = num2.size();
    int n = 1;
    while (n < n1 + n2)
        n <<= 1;

    vector<cd> a(n), b(n);
    for (int i = 0; i < n1; ++i)
        a[i] = cd(num1[n1 - 1 - i] - '0');
    for (int i = 0; i < n2; ++i)
        b[i] = cd(num2[n2 - 1 - i] - '0');

    fft(a, false);
    fft(b, false);
    for (int i = 0; i < n; ++i)
        a[i] *= b[i];
    fft(a, true);

    vector<int> result(n);
    int carry = 0;
    for (int i = 0; i < n; ++i) {
        long long val = (long long)(round(a[i].real())) + carry;
        result[i] = val % 10;
        carry = val / 10;
    }

    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }

    // Remove leading zeros
    while (result.size() > 1 && result.back() == 0)
        result.pop_back();

    string res;
    if (negative)
        res += '-';
    for (int i = result.size() - 1; i >= 0; --i)
        res += (char)(result[i] + '0');
    return res;
}

int main() {
    string num1, num2;
    // cout << "Enter first number: ";
    cin >> num1;
    // cout << "Enter second number: ";
    cin >> num2;

    // cout << "Product: " << multiply(num1, num2) << endl;
    cout << multiply(num1, num2) << endl;
    return 0;
}

