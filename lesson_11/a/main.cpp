
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    int k = 0;
    std::cin >> n;
    int a = 0, b = 1;
    for (int i = 0; i < n; i++)
    {
        int _b = b + a;
        a = b;
        b = _b;
    }
    std::cout << a << std::endl;
    return 0;
}
