#include <iostream>
using namespace std;

using very_long_num = long long;

very_long_num get_greatest_common_divisor(very_long_num x_1, very_long_num y_1)
{
    if (y_1 == 0)
    {
        return x_1;
    }
    return get_greatest_common_divisor(y_1, x_1 % y_1);
}

int main()
{
    very_long_num x_1, y_1, x_2, y_2;
    std::cin >> x_1 >> y_1;
    std::cin >> x_2 >> y_2;
    very_long_num ans = get_greatest_common_divisor((max(x_1, x_2) - min(x_1, x_2)), (max(y_1, y_2) - min(y_1, y_2)));
    ans += 1; // include the points
    std::cout << ans << "\n";
}