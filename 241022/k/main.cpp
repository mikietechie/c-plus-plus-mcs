#include <iostream>
#include <cmath>
#include <cstdint>
using namespace std;

int main(int argc, char const *argv[])
{
    long long n;
    std::cin >> n;
    auto text = "YES";
    for (long long i = 2; i <= (ceil(sqrt(n)) +1) && i < n; i++)
    {
        if (n % i == 0)
        {
            text = "NO";
            break;
        }
    }
    std::cout << text << std::endl;
    return 0;
}
