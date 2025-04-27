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
    very_long_int ans = get_extended_greatest_common_divisor(b % a, a, y, x);
    x -= (b / a) * y;
    assert(x * a + y * b == ans);

    return ans;
}

int main()
{
    very_long_int a1, x1, b1, y1;
    std::cin >> a1 >> b1;
    very_long_int gcd = get_extended_greatest_common_divisor(a1, b1, x1, y1);
    if (a1 == 1)
    {
        std::cout << -1 << "\n";
        ;
    }
    else
    {
        if (gcd != 1)
        {
            cout << -1 << "\n";
            ;
        }
        else
        {
            very_long_int ans = (y1 + abs(a1 * y1)) % a1;
            std::cout << ans << "\n";
        }
    }
    return 0;
}