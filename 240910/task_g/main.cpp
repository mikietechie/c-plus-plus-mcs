#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> f(string word, int occurances)
{
    // string output;
    vector<char> output;
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
        if (skip)
        {
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
            output.push_back(letter);
        }
    }
    sort(output.begin(), output.end());
    return output;
}

int main(int argc, char const *argv[])
{
    string word;
    std::cin >> word;
    int occurances;
    std::cin >> occurances;
    vector<char> output = f(word, occurances);
    for (auto letter : output)
    {
        std::cout << letter << " ";
    }
    // std::cout << std::endl;
    return 0;
}
