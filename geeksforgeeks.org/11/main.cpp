
/*
Q11. Write a Program to Check Whether a Number Is a Palindrome or Not.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool check_palindrome(int number)
{
    string str = to_string(number);
    string cloned = str;
    reverse(cloned.begin(), cloned.end());
    if (cloned == str)
    {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    std::cout << "Number to check = ";
    int number{};
    std::cin >> number;
    if (check_palindrome(number))
    {
        std::cout << number << " is a palindrome number." << std::endl;
    }
    else
    {
        std::cout << number << " is not a palindrome number." << std::endl;
    }

    return 0;
}
