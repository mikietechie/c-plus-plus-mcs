
/*
Q8. Write a Program to Find the Largest Among 3 Numbers.
*/

#include <iostream>
using namespace std;

char get_largest(int number1, int number2, int number3) {
    if ((number1 > number2) && (number1 > number3)) {
        return 'a';
    }
    else if ((number2 > number1) && (number2 > number3)) {
        return 'b';
    }
    else if ((number3 > number1) && (number3 > number2)) {
        return 'c';
    }
    return ' ';
}

int main(int argc, char const *argv[])
{
    int number1{};
    int number2{};
    int number3{};
    std::cout << "Enter 3 numbers" << std::endl;
    std::cin >> number1 >> number2 >> number3;
    char largest_number = get_largest(number1, number2, number3);
    std::cout << largest_number << " is the largest." << std::endl;
    return 0;
}
