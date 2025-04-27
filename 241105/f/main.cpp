#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

ll calculate_r(ll n) {
    ll r = 0;
    ll k = sqrt(n);
    
    // Handle the case where i <= sqrt(n)
    for (ll i = 1; i <= k; ++i) {
        r += n / i;
    }
    
    // Handle the case where i > sqrt(n)
    // For each possible value v of n/i, count how many i's produce this value
    for (ll v = 1; v <= n / (k + 1); ++v) {
        ll lower = n / (v + 1) + 1;
        ll upper = n / v;
        r += v * (upper - lower + 1);
    }
    
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;
    cout << calculate_r(n) << '\n';
    
    return 0;
}