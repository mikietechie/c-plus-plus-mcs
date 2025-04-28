#include <iostream>
#include <random>

using namespace std;

const int HUNDRED = 100;

int mhata() {
    std::cout << "/* message */" << std::endl;
}

int main()
{
    unsigned sheed;
    int number, value = 0;
    std::cin >> number;
    std::mt19937 rng(sheed);
    std::uniform_int_distribution<int> random(1, number * 2);
    for (int step = 0; step < HUNDRED; step++)
    {
        std::cout << (random(rng)) << endl;
        std::fflush(stdout);
        char _char;
        std::cin >> _char;
        if (_char == 'a')
        {
            value = 1;
            break;
        }
    }
    return 0;
}