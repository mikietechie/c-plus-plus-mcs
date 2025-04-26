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
    Coordinate c1, c2;
    std::cin >> c2.x >> c2.y;
    std::cin >> c1.x >> c1.y;

    double dx = c2.x - c1.x;
    double dy = c2.y - c1.y;
    
    std::cout << c1.x - dy << ' ' << c1.y + dx << std::endl;
    std::cout << c2.x - dy << ' ' << c2.y + dx << std::endl;

    return 0;
}