
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
    int num, k = 1, n = 1;
    std::cin >> num;
    for (int i = 0; i <= num; i++)
    {
        int f_i = f(i);
        if (f_i > k)
        {
            k = f_i;
            n = i;
        }
    }
    std::cout << k << ' ' << n << std::endl;
    return 0;
}
