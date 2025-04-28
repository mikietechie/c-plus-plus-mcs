
#include <iostream>
using namespace std;

using ll = long long;

int main(int argc, char const *argv[])
{
    ll n;
    ll k = 0;
    std::cin >> n;
    ll a = 0, b = 1;
    for (ll i = 0; i < n; i++)
    {
        ll _b = b + a;
        a = b;
        b = _b;
    }
    std::cout << a << std::endl;
    return 0;
}
