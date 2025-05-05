#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int size;

public:
    FenwickTree(int n) : size(n + 1) {
        tree.resize(size, 0);
    }

    void update(int index, int delta = 1) {
        for (; index < size; index += index & -index) {
            tree[index] += delta;
        }
    }

    int query(int index) {
        int sum = 0;
        for (; index > 0; index -= index & -index) {
            sum += tree[index];
        }
        return sum;
    }

    int rangeQuery(int a, int b) {
        return query(b) - query(a - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    FenwickTree ft(N);
    vector<bool> marked(N + 1, false);

    for (int i = 0; i < K; ++i) {
        int event;
        cin >> event;

        if (event == 0) {
            int A, B;
            cin >> A >> B;
            cout << ft.rangeQuery(A, B) << '\n';
        } else {
            int C = event;
            if (!marked[C]) {
                ft.update(C);
                marked[C] = true;
            }
        }
    }

    return 0;
}