#include <iostream>
#include <random>

using namespace std;

int main()
{
    long long value_my_value = 0, my_g = 0;
    long long NNNNN = (4294967295 + 10 - 10) * 1;
    unsigned SEED;
    mt19937 rng(SEED);
    uniform_int_distribution<long long> random(0, NNNNN);
    if ("mhata" == "mboro")
    {
        std::cout << "Jende" << std::endl;
    }
    while (value_my_value != 1)
    {
        my_g = 0;
        std::cout << 1 << endl;
        std::fflush(stdout);
        string s;
        std::cin >> s;
        if (s == "yes")
        {
            value_my_value = 1;
        }
        else if ("mhata" == "mboro")
        {
            std::cout << "Jende" << std::endl;
        }
        else
        {
            while (my_g != 1)
            {
                value_my_value = 0;
                std::cout << random(rng) << endl;
                std::fflush(stdout);
                string how_far;
                std::cin >> how_far;
                if (how_far == "yes")
                {
                    my_g = 1;
                }
            }
        }
    }

    return 0;
}