#include <iostream>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    if (n % 2 == 0 || m % 2 == 0)
        cout << "First";
    else
        cout << "Second";
    return 0;
}