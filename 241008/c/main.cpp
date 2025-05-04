#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;

struct TestCase
{
    uint32_t x;
    uint32_t y;
};

bool f(TestCase t)
{
    /** returns true if y can be made from x using multiplication and division by 2 */
    bool found = false;
    uint32_t current = t.x;
    for (int i = 0; i < 32; i++)
    {
        if (current == t.y) {
            found = true;
            break;
        }
        // current = (current * 2) % (1 << 32);
        current = (current * 2) % (1ULL << 32);
    }
    if (!found)
    {
        current = t.x;
        for (int i = 0; i < 32; i++)
        {
            if (current == t.y) {
                found = true;
                break;
            }
            current = current/2;
        }
    }
    return found;
}

int main(int argc, char const *argv[])
{
    vector<TestCase> test_cases;
    int length;
    std::cin >> length;
    for (int i = 0; i < length; i++)
    {
        TestCase t;
        std::cin >> t.x >> t.y;
        test_cases.push_back(t);
    }
    for (auto t : test_cases)
    {
        if (f(t))
        {
            std::cout << "Yes" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
