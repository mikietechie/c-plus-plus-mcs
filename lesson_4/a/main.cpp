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
    sort(digits.rbegin(), digits.rend());
    reverse(digits.rbegin(), digits.rend());
    for (int digit : digits)
    {
        std::cout << digit << ' ';
    }
    std::cout << std::endl;
    return 0;
}
