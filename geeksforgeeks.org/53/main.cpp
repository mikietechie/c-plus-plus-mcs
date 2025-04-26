
/*
Q53. Write a Program to Print a Calendar for a Given Year.
*/

#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[])
{
    int year{2024};
    int days_number = 365;
    if (year % 4 == 0)
    {
        days_number = 366;
    }
    
    tm first_day;
    first_day.tm_year = year;
    first_day.tm_mon = 1;
    first_day.tm_mday = 1;
    // auto datetime = mktime(&first_day);
    auto datetime = ctime(mktime(&first_day));
    std::cout << datetime << std::endl;
    return 0;
}
