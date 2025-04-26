
/*
Q6. Write a Program to Find Compound Interest.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    double principle{};
    double rate{};
    double time{};
    std::cout << "principle: ";
    std::cin >> principle;
    std::cout << "rate: ";
    std::cin >> rate;
    std::cout << "time: ";
    std::cin >> time;
    // double compound_interest = principle * rate * time / 100;
    double amount = principle * pow((1+(rate/100)),time);
    double compound_interest = amount - principle;
    std::cout << "Compund interest = " << compound_interest << std::endl;
    return 0;
}
