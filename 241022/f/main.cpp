
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, p;
    std::cin >> n >> p;
    int q = -1;
    for (int i = 0; i < n; i++)
    {
        if ((p * i) % n == 1)
        {
            q = i;
        }
    }

    std::cout << q << std::endl;
    return 0;
}
