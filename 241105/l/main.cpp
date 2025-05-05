#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SegmentTree {
    int size;
    vector<long long> tree;
    vector<long long> lazy;
    
    SegmentTree(const vector<long long>& arr) {
        size = arr.size();
        tree.resize(4 * size);
        lazy.resize(4 * size, 0);
        build(arr, 0, 0, size - 1);
    }
    
    void build(const vector<long long>& arr, int node, int left, int right) {
        if (left == right) {
            tree[node] = arr[left];
        } else {
            int mid = (left + right) / 2;
            build(arr, 2 * node + 1, left, mid);
            build(arr, 2 * node + 2, mid + 1, right);
            tree[node] = __gcd(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    void push(int node, int node_left, int node_right) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (node_left != node_right) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    
    void range_add(int node, int node_left, int node_right, int left, int right, long long x) {
        push(node, node_left, node_right);
        if (right < node_left || left > node_right) return;
        if (left <= node_left && node_right <= right) {
            lazy[node] += x;
            push(node, node_left, node_right);
            return;
        }
        int mid = (node_left + node_right) / 2;
        range_add(2 * node + 1, node_left, mid, left, right, x);
        range_add(2 * node + 2, mid + 1, node_right, left, right, x);
        tree[node] = __gcd(tree[2 * node + 1], tree[2 * node + 2]);
    }
    
    long long range_gcd(int node, int node_left, int node_right, int left, int right) {
        push(node, node_left, node_right);
        if (right < node_left || left > node_right) return 0;
        if (left <= node_left && node_right <= right) return tree[node];
        int mid = (node_left + node_right) / 2;
        long long left_gcd = range_gcd(2 * node + 1, node_left, mid, left, right);
        long long right_gcd = range_gcd(2 * node + 2, mid + 1, node_right, left, right);
        if (left_gcd == 0) return right_gcd;
        if (right_gcd == 0) return left_gcd;
        return __gcd(left_gcd, right_gcd);
    }
    
    void add(int left, int right, long long x) {
        range_add(0, 0, size - 1, left, right, x);
    }
    
    long long get_gcd(int left, int right) {
        return range_gcd(0, 0, size - 1, left, right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    SegmentTree st(a);
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            long long x;
            cin >> l >> r >> x;
            st.add(l - 1, r - 1, x); // Переводим в 0-based индексацию
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.get_gcd(l - 1, r - 1) << '\n'; // Переводим в 0-based индексацию
        }
    }
    
    return 0;
}