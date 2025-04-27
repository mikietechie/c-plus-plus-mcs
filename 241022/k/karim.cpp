#include <iostream>

using namespace std;

using very_long_int = long long;

int main()
{
    very_long_int num;
    std::cin >> num;
    very_long_int g = 0, s = 0, h = 1;
    while (h * h <= num)
    {
        if (num % h == 0)
        {
            g++;
        }
        if (h * h == num)
        {
            s = 1;
        }
        h++;
    }

    if (s == 1 || g > 1)
    {
        std::cout << "NO" << "\n";
    }
    else
    {
        std::cout << "YES" << "\n";
    }

    return 0;
}