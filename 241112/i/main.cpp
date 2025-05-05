#include <iostream>
#include <set>

using namespace std;

const int MOD = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> S;
    long long last_sum = 0;

    for (int i = 0; i < n; ++i) {
        char type;
        cin >> type;

        if (type == '+') {
            int num;
            cin >> num;

            // Обработка специального условия
            if (i > 0) {
                auto prev_op = cin.peek();
                if (prev_op == '?') {
                    num = (num + last_sum) % MOD;
                }
            }

            S.insert(num);
        } else {
            int l, r;
            cin >> l >> r;

            auto it_l = S.lower_bound(l);
            auto it_r = S.upper_bound(r);
            long long sum = 0;

            for (auto it = it_l; it != it_r; ++it) {
                sum += *it;
            }

            cout << sum << '\n';
            last_sum = sum;
        }
    }

    return 0;
}