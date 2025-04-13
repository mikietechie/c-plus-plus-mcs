#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int numbers_length, search_items_length;
    vector<int> numbers;
    vector<int> search_items;
    std::cin >> numbers_length;
    std::cin >> search_items_length;
    for (int i = 0; i < numbers_length; i++)
    {
        int digit;
        std::cin >> digit;
        numbers.push_back(digit);
    }
    for (int i = 0; i < search_items_length; i++)
    {
        int digit;
        std::cin >> digit;
        search_items.push_back(digit);
    }

    for (auto search_item : search_items)
    {
        bool found = false;
        for (auto number : numbers)
        {
            if (search_item == number)
            {
                found = true;
                std::cout << "YES" << std::endl;
                break;
            }
        }
        if (!found)
        {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
