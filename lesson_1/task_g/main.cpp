#include <string>
#include <iostream>
#include <vector>
using namespace std;


string f(string word, int occurances) {
    string output;
    vector<char> characters;
    for (auto letter : word)
    {
        bool skip = false;
        for (auto character : characters)
        {
            if (character == letter)
            {
                skip = true;
                break;
            }
        }
        if (skip) {
            continue;
        }
        characters.push_back(letter);
        int letter_count = 0;
        for (auto _letter : word)
        {
            if (_letter == letter)
            {
                letter_count++;
            }
        }
        if (occurances <= letter_count)
        {
            output = output + letter  + ' ';
        }
    }
    return output;
}

int main(int argc, char const *argv[])
{
    string word;
    std::cin >> word;
    int occurances;
    std::cin >> occurances;
    std::cout << f(word, occurances) << std::endl;
    return 0;
}
