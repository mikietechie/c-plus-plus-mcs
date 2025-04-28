#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long> weights(n);
    vector<long long> values(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> weights[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    int q;
    cin >> q;
    vector<long long> capacities(q);
    for (int i = 0; i < q; ++i)
    {
        cin >> capacities[i];
    }
    // Precompute the cumulative weights and values
    vector<long long> cumulativeWeights(n + 1, 0);
    vector<long long> cumulativeValues(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cumulativeWeights[i] = cumulativeWeights[i - 1] + weights[i - 1];
        cumulativeValues[i] = cumulativeValues[i - 1] + values[i - 1];
    }
    // Process each knapsack capacity
    for (int i = 0; i < q; ++i)
    {
        long long capacity = capacities[i];
        long long totalValue = 0;
        // Find the maximum number of items that can fit in the knapsack
        for (int j = 0; j < n; ++j)
        {
            if (cumulativeWeights[j + 1] <= capacity)
            {
                totalValue = cumulativeValues[j + 1];
            }
            else
            {
                break;
            }
        }
        cout << totalValue << endl;
    }
    return 0;
}