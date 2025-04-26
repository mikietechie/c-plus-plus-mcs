
/*
Q10. Write a Program to Check Whether a Number Is Prime or Not.
*/

#include <iostream>
#include <cmath>
using namespace std;

bool check_prime(int number)
{
    if (number == 1)
    {
        return false;
    }
    for (int i = 2; i < sqrt(number); i++)
    {
        if ((number % i) == 0)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    std::cout << "Enter number;\t";
    int number{};
    std::cin >> number;
    bool is_prime = check_prime(number);
    if (is_prime)
    {
        std::cout << number << " is a prime number." << std::endl;
    }
    else
    {
        std::cout << number << " is not a prime number." << std::endl;
    }

    return 0;
}
