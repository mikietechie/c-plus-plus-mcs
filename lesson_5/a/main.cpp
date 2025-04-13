#include <iostream>
#include <cstdint>
using namespace std;

int main(int argc, char const *argv[])
{
    int32_t A, B;
    std::cin >> A >> B;
    if (B == 0)
    {
        std::cout << "Na nol' delit' nel'zya!!!" << std::endl;
    }
    else
    {
        int Q = A / B;
        std::cout << Q << std::endl;
    }
    return 0;
}
