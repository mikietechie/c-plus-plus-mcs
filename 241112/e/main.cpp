#include <iostream>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    crope soldiers;
    for (int i = 1; i <= n; ++i) {
        soldiers.push_back('0' + i);
    }
    
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l; // convert to 0-based index
        --r;
        crope segment = soldiers.substr(l, r - l + 1);
        soldiers.erase(l, r - l + 1);
        soldiers.insert(0, segment);
    }
    
    for (int i = 0; i < n; ++i) {
        cout << soldiers[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
