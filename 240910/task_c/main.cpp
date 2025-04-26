#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string convert_base_n_to_base_10(string number, int base_n)
{
    int base_10_number = 0;
    int length = number.length();
    int counter = length;
    while (counter >= 0)
    {
        int digit = number[counter] - 48;
        int value = pow(base_n, length - (counter + 1));
        base_10_number += value * digit;
        counter -= 1;
    }
    return std::to_string(base_10_number);
}

string convert_base_10_to_base_n(string number, int base_n)
{
    string base_n_number = "";
    int numerator = std::stoi(number);
    while (numerator != 0)
    {
        int remainder = numerator % base_n;
        numerator = numerator / base_n;
        base_n_number = std::to_string(remainder) + base_n_number;
    }
    return base_n_number;
}

string sum_and_convert_to_base_n(string number, int base_n)
{
    int sum = 0;
    for (int i = 0; i < number.length(); i++)
    {
        sum += number[i] - 48;
    }
    return convert_base_10_to_base_n(std::to_string(sum), base_n);
}

string func(string number)
{
    string base_5_n = number;
    string base_10_n = convert_base_n_to_base_10(base_5_n, 5);
    string base_7_n = convert_base_10_to_base_n(base_10_n, 7);
    string sum_in_base_3 = sum_and_convert_to_base_n(base_7_n, 3);
    return sum_in_base_3;
}

int main(int argc, const char **argv)
{
    string input;
    std::cin >> input;
    std::cout << func(input) << std::endl;
    return 0;
}