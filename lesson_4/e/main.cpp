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
    sort(digits.rbegin(), digits.rend());
    reverse(digits.rbegin(), digits.rend());
    bool is_even = length % 2 == 0;
    int mid_index = length / 2;
    double median;
    if (is_even)
    {
        median = double(digits[mid_index] + digits[mid_index - 1]) / 2;
    }
    else
    {
        median = digits[mid_index];
    }
    std::cout << median << std::endl;
    return 0;
}
