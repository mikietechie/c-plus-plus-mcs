#include <iostream>
#include <string>
using namespace std;

string func(int l, int r, int d)
{
    string output = "";
    int counter = l;
    while (counter <= r)
    {
        int remainder = counter % d;
        if (remainder == 0)
        {
            if (output == "")
            {
                output = output + std::to_string(counter);
            }
            else
            {
                output = output + " " + std::to_string(counter);
            }
        }
        counter += 1;
    }
    return output;
}

int main(int argc, char const *argv[])
{
    int l, r, d;
    std::cin >> l;
    std::cin >> r;
    std::cin >> d;
    std::cout << func(l, r, d) << std::endl;
    return 0;
}
