#include <iostream>
using namespace std;

long f(long a, long b, long d)
{
    if (a == b)
    {
        return b;
    }

    if (b > a)
    {
        if (a + d >= b)
        {
            return b;
        }
        return a + d;
    }

    if (a - d <= b)
    {
        return b;
    }
    return a - d;
}

int main(int argc, char const *argv[])
{
    long a, b, d;
    cin >> a >> b >> d;
    cout << f(a, b, d) << "\n";
    return 0;
}
