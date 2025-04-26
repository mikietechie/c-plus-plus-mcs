#include <iostream>
#include <cmath>
using namespace std;

struct Coordinate
{
    double x;
    double y;
};

double get_length(Coordinate c1, Coordinate c2)
{
    return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}

int main()
{
    Coordinate c1, c2, c3;
    std::cin >> c1.x >> c1.y;
    std::cin >> c2.x >> c2.y;
    std::cin >> c3.x >> c3.y;

    double a = get_length(c1, c2);
    double b = get_length(c1, c3);
    double c = get_length(c2, c3);

    // std::cout << "a:" << a << "b:" << b << "c:" << c << std::endl;

    double s = (a + b + c) / 2;
    // std::cout << "a:" << a << "\tb:" << b << "\tc:" << c << "\ts:" << s << std::endl;

    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    std::cout << area << std::endl;

    return 0;
}