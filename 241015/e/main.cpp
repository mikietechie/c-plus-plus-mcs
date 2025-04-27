#include <iostream>
using namespace std;

struct Point
{
    double x;
    double y;
};

std::string f(Point a, Point b, Point p)
{
    if (a.x == b.x)
    {
        if (a.x == p.x)
        {
            return "YES";
        }
        else
        {
            return "NO";
        }
    }
    double ab = (a.y - b.y) / (a.x - b.x), ap = (a.y - p.y) / (a.x - p.x);
    if (ab = ap)
    {
        return "YES";
    }
    return "NO";

    double m = (a.y - b.y) / (a.x - b.x);
    double c = a.y - (m * a.x);
    if (p.y == (m * p.x + c))
    {
        return "YES";
    }
    return "NO";
};

int main(int argc, char const *argv[])
{
    Point a, b, c;
    std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    std::cout << f(a, b, c) << std::endl;
    return 0;
}
