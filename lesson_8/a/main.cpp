
#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    int x;
    int y;
};

struct Vector
{
    Point a;
    Point b;
};

int main(int argc, char const *argv[])
{
    double pow_10_5 = pow(10, 5);
    Vector v1, v2;
    // Vector a, b;
    std::cin >> v1.a.x >> v1.a.y >> v1.b.x >> v1.b.y;
    std::cin >> v2.a.x >> v2.a.y >> v2.b.x >> v2.b.y;
    return 0;
}
