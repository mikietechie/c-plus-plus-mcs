#include <iostream>
#include <string>
using namespace std;

long power(long n, long k)
{
    long v = 1;
    while (k > 0)
    {
        v *= n;
        k--;
    }
    return v;
}

string func(long n)
{
    long i = 0;
    string output = "";
    const long l = power(10, 9);
    while (1)
    {
        long v = power(n, i);
        // std::cout << "v " << v << "\n";
        if (v < l)
        {
            output = output + " " + std::to_string(v);
        }
        else
        {
            break;
        }
        i += 1;
    }
    return output;
}

int main(int argc, char const *argv[])
{
    long n;
    std::cin >> n;
    std::cout << func(n) << "\n";
    return 0;
}
