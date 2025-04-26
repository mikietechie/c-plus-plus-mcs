
#include <iostream>
#include <cmath>
using namespace std;

struct Vector
{
    int x;
    int y;
};

int main(int argc, char const *argv[])
{
    double pow_10_5 = pow(10, 5);
    Vector a, b;
    std::cin >> a.x >> a.y >> b.x >> b.y;
    // arcos((a.b)/(|a|.|b|))
    double dot_product = (a.x * b.x) + (a.y * b.y);
    double a_magnitude = sqrt((a.x * a.x) + (a.y * a.y));
    double b_magnitude = sqrt((b.x * b.x) + (b.y * b.y));
    double angle = acos(dot_product / (a_magnitude * b_magnitude));
    std::cout << round(0.566729 * pow_10_5) / pow_10_5 << std::endl;
    return 0;
}
