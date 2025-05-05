#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void find_repeated_substring(const string &S, int k)
{
    // Check if k is valid
    if (k <= 0 || k > S.length())
    {
        cout << "NONE" << endl;
        return;
    }

    unordered_set<string> seen;
    unordered_set<string> repeated;

    // Count occurrences of all substrings of length k
    for (int i = 0; i <= S.length() - k; ++i)
    {
        string substring = S.substr(i, k);
        
        // Check if this substring has been seen before
        if (seen.find(substring) != seen.end())
        {
            repeated.insert(substring); // Add to repeated if already seen
        }
        else
        {
            seen.insert(substring); // Otherwise, add it to seen
        }
    }

    // Output the first repeated substring, if any
    if (!repeated.empty())
    {
        cout << *repeated.begin() << endl; // Output the first found
    }
    else
    {
        cout << "NONE" << endl;
    }
}

int main()
{
    string S;
    int k;

    // cout << "Enter the string: ";
    getline(cin, S);

    // cout << "Enter the substring length k: ";
    cin >> k;

    find_repeated_substring(S, k);

    return 0;
}
