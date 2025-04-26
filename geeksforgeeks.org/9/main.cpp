
/*
Q9. Write a Program to Check if a Given Year Is a Leap Year.
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    std::cout << "Enter year:\t";
    int year{};
    std::cin >> year;
    if (year % 4)
    {
        std::cout << year << " is a normal year." << std::endl;
    }
    else
    {
        std::cout << year << " is a leap year." << std::endl;
    }
    return 0;
}
