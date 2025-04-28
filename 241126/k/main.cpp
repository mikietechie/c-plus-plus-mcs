#include <iostream>
using namespace std;

long long combinations(int n, int k)
{
    if (k > n)
        return 0;
    if (k > n - k)
        k = n - k; // C(n, k) == C(n, n-k)
    long long result = 1;
    for (int i = 0; i < k; ++i)
    {
        result = result * (n - i) / (i + 1);
    }
    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;
    long long result = combinations(n, k);
    cout << result << endl;
    return 0;
}