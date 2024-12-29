#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


string func(string input)
{
    int input_length = input.length();
    int n_over_2 = input_length / 2;
    string start = input.substr(0, n_over_2);
    string end = input.substr(n_over_2, input_length);
    reverse(end.begin(), end.end());
    string output = start + end;
    return output;
}

int main(int argc, char const *argv[])
{
    int length;
    std::cin >> length;
    string input;
    std::cin >> input;
    std::cout << func(input) << endl;
    return 0;
}
