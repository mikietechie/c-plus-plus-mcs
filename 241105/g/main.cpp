#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> find_powers(int p, int a, int l, int r) {
    vector<int> result;
    if (a == 0) {
        if (l <= 1 && 1 <= r) result.push_back(1);
        if (l <= 0 && 0 <= r) result.push_back(0);
        return result;
    }

    // Optimized memory usage with limited storage
    unordered_set<int> seen;
    seen.reserve(100);  // Since output is limited to 100 numbers
    long long current = 1;
    
    while (true) {
        if (l <= current && current <= r) {
            result.push_back(current);
        }
        
        if (seen.count(current)) break;
        seen.insert(current);
        current = (current * a) % p;
        
        // Early exit if we've found all possible numbers
        if (seen.size() >= p) break;  // Shouldn't happen per problem constraints
    }

    sort(result.begin(), result.end());
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, a, l, r;
    cin >> p >> a >> l >> r;

    vector<int> powers = find_powers(p, a, l, r);

    // Fast output
    if (!powers.empty()) {
        cout << powers[0];
        for (size_t i = 1; i < powers.size(); ++i) {
            cout << ' ' << powers[i];
        }
    }
    cout << '\n';

    return 0;
}

// has error