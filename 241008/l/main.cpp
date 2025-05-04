#include <iostream>
#include <bitset>
#include <cstring>
#include <string>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <algorithm>


std::string float_to_64bit_binary(long double num)
{
    // Reinterpret the bits of the long double as a 64-bit unsigned integer
    long long bits;
    std::memcpy(&bits, &num, sizeof(num));

    // Convert the 64-bit integer to a binary string
    std::bitset<80> binary(bits);
    return binary.to_string();
}

std::string float_to_64bit_hex(long double num)
{
    // Reinterpret the bits of the long double as a 64-bit unsigned integer
    long long bits;
    std::memcpy(&bits, &num, sizeof(num));

    // Convert the 64-bit integer to a hexadecimal string
    std::stringstream ss;
    ss << std::hex << std::setw(16) << std::setfill('0') << bits;
    return ss.str();
}

int main()
{
    long double p, q;
    std::cin >> p >> q;
    long double num = p / q;
    std::string binary = float_to_64bit_binary(num);
    for (int i = 0; i < binary.length(); i++)
    {
        if (i % 8 == 0 && i != 0)
        {
            std::cout << ' ';
        }

        std::cout << binary[i];
    }
    std::cout << std::endl;

    std::string hexadecimal = float_to_64bit_hex(num);
    std::transform(hexadecimal.begin(), hexadecimal.end(), hexadecimal.begin(), ::toupper);
    for (int i = 0; i < hexadecimal.length(); i++)
    {
        if (i % 2 == 0 && i != 0)
        {
            std::cout << ' ';
        }

        std::cout << hexadecimal[i];
    }
    std::cout << std::endl;

    return 0;
}