
#include <iostream>
using namespace std;

int f(int num)
{
    int k = 0;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            k++;
        }
    }

    return k;
}

int main(int argc, char const *argv[])
{
    int num, other_num;
    std::cin >> num;
    int k = f(num);
    for (int i = 0; i <= num; i++)
    {
        if (f(i) == k)
        {
            other_num = i;
        }
    }
    std::cout << k << ' ' << other_num << std::endl;
    return 0;
}
