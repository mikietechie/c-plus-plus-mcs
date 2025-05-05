
#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    double x;
    double y;
};

struct Vector
{
    Point a;
    Point b;
    double m;
    double y;
    double c;
};

Point f(Vector v1, Vector v2)
{
    Point p;
    v1.m = (v1.a.y - v1.b.y) / (v1.a.x - v1.b.x);
    v2.m = (v2.a.y - v2.b.y) / (v2.a.x - v2.b.x);
    v1.c = v1.a.y - (v1.m * v1.a.x);
    v2.c = v2.a.y - (v2.m * v2.a.x);
    // std::cout << "y = " << v1.m << "x + " << v1.c << std::endl;
    // std::cout << "y = " << v2.m << "x + " << v2.c << std::endl;

    p.x = (v1.c - v2.c) / (v2.m - v1.m);
    p.y = (v1.m * p.x) + v1.c;
    return p;
}

int main(int argc, char const *argv[])
{
    double pow_10_5 = pow(10, 5);
    Vector v1, v2;
    // Vector a, b;
    std::cin >> v1.a.x >> v1.a.y >> v1.b.x >> v1.b.y;
    std::cin >> v2.a.x >> v2.a.y >> v2.b.x >> v2.b.y;
    try
    {
        auto p = f(v1, v2);
        if (isnan(p.x) || isnan(p.y))
        {
            throw std::runtime_error("colinear, overlap or pararrel e.t.c");
        }
        else
        {
            // if (p.x > max(v1.a.x,))
            // {
            //     /* code */
            // }
            
            std::cout << p.x << ' ' << p.y << std::endl;
        }
        }
    catch (const std::exception &e)
    {
        std::cout << "-1" << std::endl;
    }

    return 0;
}
