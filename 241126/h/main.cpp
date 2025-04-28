#include <iostream>
using namespace std;
int main()
{
    long long n, k;
    cin >> n >> k;
    long long last = 0; // Josephus position for 1 person is 0 (0-indexed)
    // Calculate the position for n participants
    for (long long i = 2; i <= n; ++i)
    {
        last = (last + k) % i;
    }
    // Convert from 0-indexed to 1-indexed
    cout << last + 1 << endl;
    return 0;
}