#include <cassert>
#include <iostream>

using namespace std;

using very_long_int = long long;

very_long_int get_extended_greatest_common_divisor(very_long_int a, very_long_int b, very_long_int &x, very_long_int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    very_long_int res = get_extended_greatest_common_divisor(b % a, a, y, x);
    x -= (b / a) * y;
    assert(x * a + y * b == res);
    return res;
}

int main()
{
    very_long_int n, x1, p, y1;
    std::cin >> n >> p;
    if (p == 0)
    {
        std::cout << -1;
    }
    else
    {
        get_extended_greatest_common_divisor(n, p, x1, y1);
        very_long_int g = (y1 + n) % n;
        std::cout << g << "\n";
    }
}