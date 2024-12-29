#include <string>
#include <cstring>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char func(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        string chr = to_string(i);
        if (strstr(input.c_str(), chr.c_str()) == 0)
        {
            return chr[0];
        }
    }
    return ' ';
}

int main(int argc, char const *argv[])
{
    int length;
    std::cin >> length;
    string input;
    std::cin >> input;
    std::cout << func(input) << endl;
    return 0;
}
