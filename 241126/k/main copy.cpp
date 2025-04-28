#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int ncr(int n, int r)
{
    return factorial(n) / (factorial(n - r) * factorial(r));
}

int main(int argc, char const *argv[])
{
    int n, r;
    std::cin >> n >> r;
    std::cout << ncr(n, r) << std::endl;
    return 0;
}
