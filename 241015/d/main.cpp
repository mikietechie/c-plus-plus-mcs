
#include <iostream>
#include <cmath>
using namespace std;

struct Circle
{
    int x;
    int y;
    int r;
};

int main(int argc, char const *argv[])
{
    double pow_10_5 = pow(10, 5);
    Circle c1, c2;
    // Circle a, b;
    std::cin >> c1.x >> c1.y >> c1.r;
    std::cin >> c2.x >> c2.y >> c2.r;
    double x = (-pow(c1.x, 2) + pow(c2.x, 2) - (2));
    return 0;
}
