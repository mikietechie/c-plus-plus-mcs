#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int length;
    std::cin >> length;
    if (length == 0)
    {
        return 0;
    }
    vector<int> digits;
    for (int i = 0; i < length; i++)
    {
        int digit;
        std::cin >> digit;
        digits.push_back(digit);
    }
    int most_frequent_digit = digits[0];
    int most_frequent_digit_count = 1;
    for (auto digit : digits)
    {
        int digit_count = 0;
        for (auto _digit : digits)
        {
            if (digit == _digit)
            {
                digit_count++;
            }
        }
        if (digit_count > most_frequent_digit_count)
        {
            most_frequent_digit_count = digit_count;
            most_frequent_digit = digit;
        }
    }
    std::cout << most_frequent_digit << endl;
    return 0;
}
