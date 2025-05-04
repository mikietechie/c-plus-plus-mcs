#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

using ll = long long;

int main(int argc, char const *argv[])
{
    ll count;
    ll largest = pow(10, 9);
    std::cin >> count;
    std::vector<ll> digits;

    for (ll i = 0; i < count; i++)
    {
        ll ai;
        std::cin >> ai;
        digits.push_back(ai);
        // largest = std::max(largest, ai);
    }
    for (ll i = 0; i < largest; i++)
    {
        if (std::find(digits.begin(), digits.end(), i) == digits.end())
        {
            std::cout << i << std::endl;
            break;
        }
    }

    return 0;
}
