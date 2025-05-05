#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct SegmentTree {
    int size;
    vector<pair<int, int>> tree; // храним (значение, индекс)
    
    SegmentTree(const vector<int>& arr) {
        size = arr.size();
        tree.resize(4 * size);
        build(arr, 0, 0, size - 1);
    }
    
    void build(const vector<int>& arr, int node, int left, int right) {
        if (left == right) {
            tree[node] = {arr[left], left};
        } else {
            int mid = (left + right) / 2;
            build(arr, 2 * node + 1, left, mid);
            build(arr, 2 * node + 2, mid + 1, right);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    pair<int, int> query(int node, int node_left, int node_right, int left, int right) {
        if (right < node_left || left > node_right) {
            return {INT_MAX, -1};
        }
        if (left <= node_left && node_right <= right) {
            return tree[node];
        }
        int mid = (node_left + node_right) / 2;
        return min(
            query(2 * node + 1, node_left, mid, left, right),
            query(2 * node + 2, mid + 1, node_right, left, right)
        );
    }
    
    pair<int, int> get_min(int left, int right) {
        return query(0, 0, size - 1, left, right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    SegmentTree st(A);
    
    for (int i = 0; i < M; ++i) {
        int k, l;
        cin >> k >> l;
        // Переводим в 0-based индексацию
        k--; l--;
        pair<int, int> res = st.get_min(k, l);
        // Выводим индекс в 1-based
        cout << res.second + 1 << '\n';
    }
    
    return 0;
}