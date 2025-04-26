#include <iostream>
#include <string>
using namespace std;

string func(string s, string t)
{
    // Remove every char in t from s
    string output = "";
    int s_length = s.length();
    int t_length = t.length();
    int outer_index = 0;
    while (outer_index < s_length)
    {
        char s_char = s[outer_index];
        int inner_index = 0;
        bool is_in_t = 0;
        while (inner_index < t_length)
        {
            char t_char = t[inner_index];
            if (t_char == s_char)
            {
                is_in_t = 1;
                break;
            }
            inner_index += 1;
        }
        if (is_in_t == 0)
        {
            output = output + s_char;
        }
        outer_index += 1;
    }
    return output;
}

int main(int argc, char const *argv[])
{
    // std::cout << func("cabbage", "face") << std::endl;
    // std::cout << func("aba", "bb") << std::endl;
    string input_s;
    std::cin >> input_s;
    string input_t;
    std::cin >> input_t;
    std::cout << func(input_s, input_t) << std::endl;
    return 0;
}
