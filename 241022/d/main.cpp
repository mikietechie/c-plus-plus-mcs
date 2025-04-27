#include <iostream>
using namespace std;

using long_int = long long;

int main()
{
    long_int num;
    std::cin >> num;
    long_int var1 = 0, var2 = 0, var3 = 1;
    while (var3 * var3 <= num)
    {
        if (num % var3 == 0)
        {
            var1 += 1;
        }
        if (var3 * var3 == num)
        {
            var2 = 1;
        }
        var3 += 1;
    }
    long_int ans;
    if (var2 == 1)
    {
        ans = 2 * var1 - 1;
    }
    else
    {
        ans = 2 * var1;
    }
    std::cout << ans << "\n";

    return 0;
}