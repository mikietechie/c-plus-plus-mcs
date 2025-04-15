#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int r = 2, b = 3, k = 0, l, n;
    std::cin >> l;
    for (int ri = 0; ri <= l / r; ri++)
    {
        int reds = r * ri;
        for (int bi = 0; bi <= l / b; bi++)
        {
            int blues = b * bi;
            int _l = reds + blues;
            if (_l == l)
            {
                k++;
            }
        }
    }
    std::cout << k << std::endl;
    return 0;
}
