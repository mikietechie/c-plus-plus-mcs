
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    std::cin >> num;
    int count = 1;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
