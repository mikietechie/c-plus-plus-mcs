#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int length;
    std::cin >> length;
    vector<int> digits;
    int minimum = pow(10, 9);
    int maximum = minimum * -1;
    for (int i = 0; i < length; i++)
    {
        int digit;
        std::cin >> digit;
        digits.push_back(digit);
        if (digit > maximum)
        {
            maximum = digit;
        } else if (digit < minimum) {
            minimum = digit;
        }

    }
    // std::cout << minimum << "\t:\t" << maximum << std::endl;
    for (int i = 0; i < maximum; i++)
    {
        bool found = false;
        for (int digit : digits)
        {
            if (digit == i)
            {
                found = true;
            }
        }
        if (found)
        {
            continue;
        }
        std::cout << i << std::endl;
        break;
    }
    return 0;
}
