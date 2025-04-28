#include <iostream>

using namespace std;
using ll = long long;

int main()
{
    long long num;
    std::cin >> num;
    const int num33 = 33, num32=32;
    for (int i = 1; i <= num33; ++i)
    {
        std::cout << 'a';
    }
    std::cout << "\n";
    std::cout << 'b';
    for (int i = 1; i <= num32; ++i)
    {
        std::cout << 'a';
    }
    std::cout << "\n";
}