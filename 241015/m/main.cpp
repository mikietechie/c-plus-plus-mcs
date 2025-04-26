#include <iostream>
#include <cmath>
using namespace std;

struct Coordinate
{
    double x;
    double y;
};

int main()
{
    Coordinate c1, c2, c3;
    std::cin >> c1.x >> c1.y;
    std::cin >> c2.x >> c2.y;
    std::cin >> c3.x >> c3.y;

    double a = ((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y));
    double b = ((c2.x - c3.x) * (c2.x - c3.x) + (c2.y - c3.y) * (c2.y - c3.y));
    double c = ((c3.x - c1.x) * (c3.x - c1.x) + (c3.y - c1.y) * (c3.y - c1.y));
    double A = max(a, max(b, c));
    double C = min(a, min(b, c));
    double B = a + b + c - A - C;
    double sqrt_A = sqrt(A);
    double sqrt_B = sqrt(B);
    double sqrt_C = sqrt(C);

    if (sqrt_A == (sqrt_B + sqrt_C))
    {
        std::cout << "degenerate" << std::endl;
    }
    else if (A == B + C)
    {
        std::cout << "right" << std::endl;
    }
    else if (A < B + C)
    {
        std::cout << "acute" << std::endl;
    }
    else if (A > B + C)
    {
        std::cout << "obtuse" << std::endl;
    }

    return 0;
}