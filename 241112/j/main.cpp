#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SegmentTree {
    int size;
    vector<long long> tree;
    vector<bool> lazy;
    
    SegmentTree(const vector<int>& data) {
        size = 1;
        while (size < data.size()) size <<= 1;
        tree.resize(2 * size);
        lazy.resize(2 * size, false);
        
        for (int i = 0; i < data.size(); ++i) {
            tree[size + i] = data[i];
        }
        for (int i = size - 1; i > 0; --i) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }
    
    void push(int node, int node_len) {
        if (lazy[node]) {
            lazy[node] = false;
            if (node_len > 1) {
                lazy[2 * node] ^= true;
                lazy[2 * node + 1] ^= true;
                swap(tree[2 * node], tree[2 * node + 1]);
            }
        }
    }
    
    void range_swap(int l, int r, int node = 1, int node_l = 0, int node_r = -1) {
        if (node_r == -1) node_r = size - 1;
        if (r < node_l || node_r < l) return;
        if (l <= node_l && node_r <= r) {
            lazy[node] ^= true;
            return;
        }
        push(node, node_r - node_l + 1);
        int mid = (node_l + node_r) / 2;
        range_swap(l, r, 2 * node, node_l, mid);
        range_swap(l, r, 2 * node + 1, mid + 1, node_r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    long long range_sum(int l, int r, int node = 1, int node_l = 0, int node_r = -1) {
        if (node_r == -1) node_r = size - 1;
        if (r < node_l || node_r < l) return 0;
        if (l <= node_l && node_r <= r) return tree[node];
        push(node, node_r - node_l + 1);
        int mid = (node_l + node_r) / 2;
        return range_sum(l, r, 2 * node, node_l, mid) + 
               range_sum(l, r, 2 * node + 1, mid + 1, node_r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    bool first_case = true;
    
    while (cin >> N >> M, N != 0 || M != 0) {
        if (!first_case) cout << "\n";
        first_case = false;
        
        vector<int> data(N);
        for (int i = 0; i < N; ++i) {
            cin >> data[i];
        }
        
        SegmentTree st(data);
        
        while (M--) {
            int type, x, y;
            cin >> type >> x >> y;
            x--; y--; // convert to 0-based
            
            if (type == 1) {
                // Swap operation (only for even length segments)
                if ((y - x + 1) % 2 == 0) {
                    st.range_swap(x, y);
                }
            } else {
                // Sum query
                cout << st.range_sum(x, y) << "\n";
            }
        }
    }
    
    return 0;
}