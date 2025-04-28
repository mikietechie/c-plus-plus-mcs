// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N, M;
//     cin >> N >> M;

//     // Read input array and compute prefix sums
//     vector<long long> prefix(N + 1, 0);
//     for (int i = 1; i <= N; ++i) {
//         int num;
//         cin >> num;
//         prefix[i] = prefix[i - 1] + num;
//     }

//     // Process queries
//     for (int q = 0; q < M; ++q) {
//         int k, l;
//         cin >> k >> l;

//         // Note: converting to 1-based indexing if input is 0-based
//         // Assuming input uses 1-based indexing (as per problem statement)
//         cout << prefix[l] - prefix[k - 1] << '\n';
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long m, n;
    cin >> m >> n;

    vector<long long> numbers(m);
    for (long long i = 0; i < m; ++i)
    {
        cin >> numbers[i];
    }

    vector<string> sums;
    for (long long i = 0; i < n; ++i)
    {
        long long start, end;
        cin >> start >> end;

        // Corrected indices: end is inclusive in the problem
        long long sum = 0;
        for (long long i = start-1; i < end; i++)
        {
            sum += numbers[i];
        }

        // long long sum = accumulate(numbers.begin() + (start - 1),
        //                   numbers.begin() + end, 0);
        sums.push_back(to_string(sum));
    }

    for (const string &s : sums)
    {
        cout << s << "\n";
    }

    return 0;
}
