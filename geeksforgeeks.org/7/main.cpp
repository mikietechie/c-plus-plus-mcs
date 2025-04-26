
/*
Q7. Write a Program to Check Even or Odd Integers.
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    std::cout << "Number = ";
    int number{};
    std::cin >> number;
    if (number % 2)
    {
        std::cout << number << " is Odd Number." << std::endl;
    }
    else
    {
        std::cout << number << " is Even Number." << std::endl;
    }
    return 0;
}
