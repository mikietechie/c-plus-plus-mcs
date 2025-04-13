#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int length;
    std::cin >> length;
    vector<int> digits;
    for (int i = 0; i < length; i++)
    {
        int digit;
        std::cin >> digit;
        digits.push_back(digit);
    }
    int count = 0;
    for (int outer_index = 0; outer_index < length; outer_index++)
    {
        int outer_element = digits[outer_index];
        for (int inner_index = 0; inner_index < length; inner_index++)
        {
            int inner_element = digits[inner_index];
            if ((outer_index < inner_index) && (outer_element > inner_element))
            {
                count++;
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}
