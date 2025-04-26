
/*
Q5. Write a Program to Find the Size of int, float, double, and char.
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    long long_var = 10L;
    int int_var = 10;
    float float_var = .99f;
    double double_var = .99;
    char char_var = 'x';
    std::cout << "size of long : " << sizeof(long_var) << " bytes" << std::endl;
    std::cout << "size of int : " << sizeof(int_var) << " bytes" << std::endl;
    std::cout << "size of float : " << sizeof(float_var) << " bytes" << std::endl;
    std::cout << "size of double : " << sizeof(double_var) << " bytes" << std::endl;
    std::cout << "size of char : " << sizeof(char_var) << " bytes" << std::endl;
    std::cout << "" << std::endl;
    return 0;
}
