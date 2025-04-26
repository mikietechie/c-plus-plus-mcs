
/*
Q3. Write a Program to Print the ASCII Value of a Character.
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char character{};
    std::cout << "Character: ";
    std::cin >> character;
    std::cout << "ASCII Value of '" << character << "' = " << int(character) << std::endl;
    return 0;
}
