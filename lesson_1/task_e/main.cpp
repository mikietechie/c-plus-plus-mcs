#include <iostream>
#include <string>
using namespace std;

char func(string word)
{ // Find the most common letter
    int word_length = word.length();
    int outer_index = 0;
    char most_common_char;
    int most_common_count = 0;
    char current_char;
    if (word_length > 0)
    {
        most_common_char = word[0];
        // current_char = word;
    }
    while (outer_index < word_length)
    {
        current_char = word[outer_index];
        int current_count = 0;
        int inner_index = 0;
        while (inner_index < word_length)
        {
            char char_at_index = word[inner_index];
            if (char_at_index == current_char)
            {
                current_count += 1;
            }
            inner_index += 1;
        }
        if (current_count > most_common_count)
        {
            most_common_count = current_count;
            most_common_char = current_char;
        }
        outer_index += 1;
    }
    return most_common_char;
}

int main(int argc, char const *argv[])
{
    string input;
    std::cin >> input;
    std::cout << func(input) << std::endl;
    return 0;
}
