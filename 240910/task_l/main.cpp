#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int length;
    std::cin >> length;
    vector<int> digits;
    int maximum = 0;
    for (int i = 0; i < length; i++)
    {
        int digit;
        std::cin >> digit;
        digits.push_back(digit);
        if (digit > maximum)
        {
            maximum = digit;
        }
    }
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
