#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int length;
    std::cin >> length;
    if (length == 0)
    {
        return 0;
    }
    int first_digit;
    vector<int> digits;
    for (int i = 0; i < length; i++)
    {
        int digit;
        std::cin >> digit;
        digits.push_back(digit);
        if (i == 0)
        {
            first_digit = digit;
        }
    }
    sort(digits.rbegin(), digits.rend());
    // reverse(digits.rbegin(), digits.rend());

    // std::cout << "..........." << std::endl;
    // std::cout << first_digit << std::endl;
    for (int i = 0; i < length; i++)
    {
        // std::cout << i+1 << "\t:\t" << digits[i] << std::endl;
        if (digits[i] == first_digit)
        {
            std::cout << length-i << std::endl;
            break;
        }
    }
    return 0;
}
