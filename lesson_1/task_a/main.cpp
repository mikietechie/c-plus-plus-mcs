#include <iostream>
using namespace std;

int f(int a, int b, int d)
{
    int n = a + d;
    if (a > b)
    {
        n = a - d;
    }
    if (n >= b)
    {
        n = b;
    }
    return n;
}

int main(int argc, char const *argv[])
{
    int a, b, d;
    cin >> a >> b >> d;
    cout << f(a, b, d) << "\n";
    return 0;
}
