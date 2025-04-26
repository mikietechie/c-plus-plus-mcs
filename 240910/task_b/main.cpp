#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string func(long n)
{
    long i = 0;
    string output = "";
    const long l = pow(10, 9);
    while (1)
    {
        long v = pow(n, i);
        // std::cout << "v " << v << "\n";
        if (v < l)
        {
            string join = " ";
            if (output == "")
            {
                join = "";
            }        
            output = output + join + std::to_string(v);
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
