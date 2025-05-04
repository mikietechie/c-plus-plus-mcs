
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main(int argc, char const *argv[])
{
    ll n, x;
    vector<ll> arr;
    std::cin >> n >> x;
    for (ll i = 0; i < n; i++)
    {
        ll ai;
        std::cin >> ai;
        arr.push_back(ai);
    }
    for(auto a : arr)
    {
        if (find(arr.begin(), arr.end(), x - a) != arr.end())
        {
            std::cout << "YES" << std::endl;
            return 0;
        }
        
    }

    return 0;
}
