
/*
Q4. Write a Program to Swap Two Numbers.
*/

#include <iostream>
using namespace std;

void swap_ints(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main(int argc, char const *argv[])
{
    int a{};
    int b{};
    std::cout << "Enter A: ";
    std::cin >> a;
    std::cout << "Enter B: ";
    std::cin >> b;
    swap_ints(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    return 0;
}
