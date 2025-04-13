#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <cstdint>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int16_t num;
    std::cin >> num;
    stringstream hex_stream;
    stringstream bin_stream;
    string hex_string;
    string bin_string;
    hex_stream << std::hex << num;
    bin_stream << std::bitset<16>(num).to_string();
    hex_string = hex_stream.str();
    bin_string = bin_stream.str();
    std::transform(hex_string.begin(), hex_string.end(), hex_string.begin(), ::toupper);
    std::transform(bin_string.begin(), bin_string.end(), bin_string.begin(), ::toupper);
    for (int i = 0; i < 16; i++)
    {
        if (i == 8)
        {
            std::cout << ' ';
        }
        std::cout << bin_string[i];
    }
    std::cout << std::endl;
    int hex_string_length = hex_string.length();
    if (hex_string_length < 4)
    {
        for (int i = 0; i < 4-hex_string_length; i++)
        {
            hex_string = "0" + hex_string;
        }
        hex_string_length = hex_string.length();
    }
    
    for (int i = hex_string_length - 4; i < hex_string_length; i++)
    {
        if (i == hex_string_length - 2)
        {
            std::cout << ' ';
        }
        std::cout << hex_string[i];
    }
    std::cout << std::endl;
    return 0;
}
