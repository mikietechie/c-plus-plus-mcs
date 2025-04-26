
/*
Q12. Write a Program to Make a Simple Calculator.
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float number_1{};
    float number_2{};
    char operand;

    std::cout << "Calculator" << std::endl;
    std::cout << "Enter two numbers" << std::endl;
    std::cin >> number_1 >> number_2;
    std::cout << "\nEnter operand\na for addition\ns for subtraction\nm for multiplication\nd for division\n"
              << std::endl;
    std::cin >> operand;

    switch (operand)
    {
    case 'a':
        std::cout << number_1 << " + " << number_2 << " = " << (number_1 + number_2) << std::endl;
        break;
    case 's':
        std::cout << number_1 << " - " << number_2 << " = " << (number_1 - number_2) << std::endl;
        break;
    case 'm':
        std::cout << number_1 << " * " << number_2 << " = " << (number_1 * number_2) << std::endl;
        break;
    case 'd':
        std::cout << number_1 << " / " << number_2 << " = " << (number_1 / number_2) << std::endl;
        break;
    default:
        std::cout << "Unidentified operand" << std::endl;
        break;
    }
    return 0;
}
