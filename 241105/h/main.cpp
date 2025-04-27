#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // Read input array and compute prefix sums
    vector<long long> prefix(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        int num;
        cin >> num;
        prefix[i] = prefix[i - 1] + num;
    }

    // Process queries
    for (int q = 0; q < M; ++q) {
        int k, l;
        cin >> k >> l;
        
        // Note: converting to 1-based indexing if input is 0-based
        // Assuming input uses 1-based indexing (as per problem statement)
        cout << prefix[l] - prefix[k - 1] << '\n';
    }

    return 0;
}