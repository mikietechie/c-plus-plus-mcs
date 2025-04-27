// Used AI

#include <iostream>
#include <tuple>

using namespace std;

tuple<int, int, int> extended_gcd(int a, int b)
{
    if (b == 0)
    {
        return make_tuple(a, 1, 0);
    }
    else
    {
        int gcd, x1, y1;
        tie(gcd, x1, y1) = extended_gcd(b, a % b);
        int x = y1;
        int y = x1 - (a / b) * y1;
        return make_tuple(gcd, x, y);
    }
}

pair<int, int> find_xy(int A, int B)
{
    int gcd, X, Y;
    tie(gcd, X, Y) = extended_gcd(A, B);
    if (gcd != 1)
    {
        return make_pair(0, 0);
    }
    else
    {
        // Check if X and Y are within bounds
        if (X >= -10000 && X <= 10000 && Y >= -10000 && Y <= 10000)
        {
            return make_pair(X, Y);
        }
        else
        {
            return make_pair(0, 0); // No valid solution within constraints
        }
    }
}

int main()
{
    int A, B;
    std::cin >> A >> B;
    auto [X, Y] = find_xy(A, B);
    std::cout << X << " " << Y << endl; // Output: X = 0, Y = 0 (since gcd(35,15)=5≠1)
    return 0;
}