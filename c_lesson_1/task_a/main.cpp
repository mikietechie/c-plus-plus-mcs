#include <iostream>
using namespace std;

int move(int a, int b, int d)
{
    int next_n = a + d;
    if (a > b)
    {
        next_n = a - d;
    }
    if (next_n >= b)
    {
        return b;
    }
    return next_n;
}

int main(int argc, char const *argv[])
{
    int a, b, d;
    std::cin >> a;
    std::cin >> b;
    std::cin >> d;
    std::cout << move(a,b,d) << "\n";
    return 0;
}
