#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int length;
    std::cin >> length;
    int half = length / 2;
    vector<int> digits1;
    vector<int> digits2;
    for (int i = 0; i < length; i++)
    {
        int digit;
        std::cin >> digit;
        if (i < half)
        {
            digits1.push_back(digit);
        }
        else
        {
            digits2.push_back(digit);
        }
    }
    sort(digits1.rbegin(), digits1.rend());
    reverse(digits1.rbegin(), digits1.rend());
    sort(digits2.rbegin(), digits2.rend());

    for (auto digit : digits1)
    {
        std::cout << digit << ' ';
    }

    for (auto digit : digits2)
    {
        std::cout << digit << ' ';
    }
    std::cout << std::endl;
    return 0;
}
