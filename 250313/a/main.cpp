
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    long long n, sum = 0;
    std::cin >> n;
    for (long long i = 0; i < n; i++)
    {
        long long num;
        std::cin >> num;
        sum = sum + num;
    }
    std::cout << sum << std::endl;
    return 0;
}
