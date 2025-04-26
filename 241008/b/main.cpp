#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

int main(int argc, char const *argv[])
{
    int64_t A, B;
    std::cin >> A >> B;
    if (B == 0)
    {
        std::cout << "Na nol' delit' nel'zya!!!" << std::endl;
    }
    else if (abs(A) < abs(B))
    {
        std::cout << 0 << std::endl;
    }
    else if (A >= 0 && B > 0)
    {
        int64_t Q = A/B;
        std::cout << Q << std::endl;
    }
    else if (A < 0 && B < 0)
    {
        int64_t Q = abs(A)/abs(B);
        std::cout << Q << std::endl;
    }
    else
    {
        int64_t Q = -1 * (abs(A)/abs(B));
        std::cout << Q << std::endl;
    }
    return 0;
}
