#include <stdio.h>

long power(long n, long k)
{
    long v = 1;
    while (k > 0)
    {
        v *= n;
        k--;
    }
    return v;
}

long func(long n)
{
    char output[] = "";
    long i = 0;
    const long l = power(10, 9);
    while (1)
    {
        long v = power(n, i);
        if (v >= l)
        {
            break;
        }
        output = output + "";
    }
}

int main(int argc, char const *argv[])
{
    printf("Ans\t:\t%ld\n", power(2, 2));
    return 0;
}
