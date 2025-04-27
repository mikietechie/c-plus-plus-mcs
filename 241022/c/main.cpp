#include <iostream>
#include <stdio.h>
using namespace std;

using very_long_int = long long;
using int128 = __int128;

very_long_int get_greatest_common_divisor(very_long_int num_1, very_long_int num_2)
{
    if (num_2 == 0)
    {
        return num_1;
    }
    return get_greatest_common_divisor(num_2, num_1 % num_2);
}

int main()
{
    very_long_int n, k, l, m;
    std::cin >> k >> l >> m >> n;
    int128 var1 = get_greatest_common_divisor(k, l);
    int128 var2 = get_greatest_common_divisor(k, m);
    int128 var3 = get_greatest_common_divisor(m, l);
    int128 var4 = k / var1 * l;
    int128 var5 = var4 / get_greatest_common_divisor(var4, m) * m;
    int128 var6 = l / var1 * k;
    int128 var7 = l / var3 * m;
    int128 var8 = m / var2 * k;
    very_long_int x = (n / l + n / m + n / k - n / var6 - n / var7 - n / var8 + n / var5);
    std::cout << x << "\n";
}