
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> tsvaga_masimba(int p, int a, int l, int r) {
    if (a == 0) {
        vector<int> res;
        if (l <= 1 && 1 <= r) res.push_back(1);
        if (l <= 0 && 0 <= r) res.push_back(0);
        return res;
    }

    vector<int> result;
    unordered_set<int> seen;
    long long current = 1;  // a^0 mod p = 1
    
    // Pre-allocate space for the common case
    result.reserve(100);
    seen.reserve(100);

    while (true) {
        if (l <= current && current <= r) {
            result.push_back(current);
        }
        
        seen.insert(current);
        current = (current * a) % p;
        
        if (seen.count(current)) break;
    }

    sort(result.begin(), result.end());
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, a, l, r;
    cin >> p >> a >> l >> r;

    vector<int> masimba = tsvaga_masimba(p, a, l, r);

    // Fast output without iostream overhead
    if (!masimba.empty()) {
        cout << masimba[0];
        for (size_t i = 1; i < masimba.size(); ++i) {
            cout << ' ' << masimba[i];
        }
    }
    cout << '\n';

    return 0;
}