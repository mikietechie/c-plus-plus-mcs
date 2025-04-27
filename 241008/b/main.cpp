/*Troublesome assignment*/
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdint>
using namespace std;

int main()
{
    const unsigned long long LIMIT = 9223372036854775808;
    const std::string LIMIT_STR = "9223372036854775808";
    int64_t num_1, num_2;
    std::cin >> num_1 >> num_2;
    if (num_2 == 0)
    {
        // zero division error
        std::cout << "Na nol' delit' nel'zya!!!";
    }
    else
    {
        if (num_1 == -LIMIT && num_2 == -1)
        {
            std::cout << LIMIT_STR << "\n";
        }
        else
        {
            if (num_1 % num_2 == 0)
                std::cout << setprecision(0) << num_1 / num_2;
            else
            {
                if ((num_1 < 0 && num_2 > 0))
                {
                    std::cout << num_1 / num_2 - 1 << "\n";
                }
                else if (num_1 >= 0 && num_2 < 0)
                {
                    std::cout << num_1 / num_2 << "\n";
                }
                else if (num_2 > 0 && num_1 >= 0)
                {
                    std::cout << num_1 / num_2 << "\n";
                }
                else if (num_1 < 0 && num_2 < 0)
                {
                    std::cout << num_1 / num_2 + 1 << "\n";
                }
            }
        }
    }
    return 0;
}