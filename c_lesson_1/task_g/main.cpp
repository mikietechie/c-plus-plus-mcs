#include <string>
#include <iostream>
using namespace std;

int count(string str, char chr)
{
    int n = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == chr)
        {
            n++;
        }
    }
    return n;
}

bool contains(string str, char chr)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == chr)
        {
            return 1;
        }
    }
    return 0;
}

string func(string input, int k)
{
    string output = "";
    for (int i = 0; i < input.length(); i++)
    {
        char chr = input[i];
        if (contains(output, chr))
        {
            continue;
        }
        if (count(input, chr) >= k)
        {
            cout << chr << endl;
            if (output == "")
            {
                output = chr;
            }
            else
            {
                output = output + " " + chr;
            }
        }
    }

    return output;
}

int main(int argc, char const *argv[])
{
    string input;
    std::cin >> input;
    int k;
    std::cin >> k;
    std::cout << func(input, k) << std::endl;
    return 0;
}
