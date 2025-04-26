#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int length;
    std::cin >> length;
    vector<int> digits;
    for (int i = 0; i < length; i++)
    {
        int digit;
        std::cin >> digit;
        digits.push_back(digit);
    }
    for (auto digit : digits)
    {
        int count = 0;
        for (auto _digit : digits)
        {
            if (digit == _digit)
            {
                count++;
            }
        }
        if (count == 1)
        {
            std::cout << digit << std::endl;
            break;
        }
    }
    return 0;
}
