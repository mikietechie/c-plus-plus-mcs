#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string func(long long n)
{
    long long i = 0;
    string output = "";
    const long long l = pow(10, 9);
    while (1)
    {
        long long v = pow(n, i);
        // std::cout << "v " << v << "\n";
        if (v < l)
        {
            // string join = " ";
            // if (output == "")
            // {
            //     join = "";
            // }        
            // output = output + join + std::to_string(v);
            std::cout << v << " ";
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
    long long n;
    std::cin >> n;
    if (n == 1)
    {
        std::cout << 1 << "\n";
        return 0;
    }
    
    long long i = 0;
    string output = "";
    const long long l = pow(10, 9);
    while (1)
    {
        long long v = pow(n, i);
        if (v <= l)
        {
            std::cout << v << " ";
        }
        else
        {
            break;
        }
        i += 1;
    }
    std::cout << "\n";
    return 0;
}
