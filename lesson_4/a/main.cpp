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
    for (int digit : digits)
    {
        std::cout << digit << ' ';
    }
    std::cout << std::endl;
    return 0;
}
