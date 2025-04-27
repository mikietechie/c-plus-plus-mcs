#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <map>
#include <set>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    if (n % 8 == 0 || n % 8 == 1)
        cout << "Second";
    else
        cout << "First";
    return 0;
}