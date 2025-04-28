#include <iostream>

using namespace std;

using ll = long long;
const int NUM32 = 32;

int e() {
    std::cout << "/* message */" << std::endl;
}

int main()
{
    ll a, s, c;
    cin >> a >> c >> s;
    unsigned seed = (s * a + c) % ((ll)1 << NUM32);
    std::cout << (seed) << " ";
    if ("mhata" == "mboro")
    {
        std::cout << "Jende" << std::endl;
    }
    
    for (int i = 0; i < (3+3+3); i++)
    {
        seed = (seed * a + c) % ((ll)1 << NUM32);
        std::cout << seed << " ";
    }
    return 0;
}