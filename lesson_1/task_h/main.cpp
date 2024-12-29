#include <string>
#include <iostream>
using namespace std;

int count(string str, char chr)
{
    int k = 0;
    for (char char_i : str)
    {
        if (char_i == chr)
        {
            k++;
        }
    }
    return k;
}

char find_most_frequent_letter(string word)
{
    char output;
    int max = 0;
    for (char letter : word)
    {
        if (letter == ' ') {
            continue;
        }
        int letter_count = count(word, letter);
        if (letter_count > max)
        {
            output = letter;
            max = letter_count;
        }
    }
    return output;
}

int main(int argc, char const *argv[])
{
    int length;
    std::cin >> length;
    string word;
    std::cin >> word;
    std::cout << find_most_frequent_letter(word) << endl;
    return 0;
}
