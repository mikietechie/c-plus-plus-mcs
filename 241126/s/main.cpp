#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> sequence;
    int num;
    while (cin >> num) {
        sequence.push_back(num);
    }

    vector<int> tails;
    for (int x : sequence) {
        // Ищем первый элемент в tails, который <= x
        auto it = upper_bound(tails.begin(), tails.end(), x, greater<int>());
        if (it == tails.end()) {
            tails.push_back(x);
        } else {
            *it = x;
        }
    }

    cout << tails.size() << '\n';

    return 0;
}