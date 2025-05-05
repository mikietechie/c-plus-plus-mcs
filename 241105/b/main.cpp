#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> rank;
    vector<int> color; // 0 или 1
    
    DSU(int n) : parent(n + 1), rank(n + 1, 0), color(n + 1, 0) {
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }
    
    pair<int, int> find(int x) {
        if (parent[x] != x) {
            auto [root, col] = find(parent[x]);
            color[x] ^= col;
            parent[x] = root;
        }
        return {parent[x], color[x]};
    }
    
    bool union_sets(int a, int b) {
        auto [root_a, col_a] = find(a);
        auto [root_b, col_b] = find(b);
        
        if (root_a == root_b) {
            return col_a != col_b;
        }
        
        if (rank[root_a] > rank[root_b]) {
            swap(root_a, root_b);
        }
        
        parent[root_a] = root_b;
        color[root_a] = col_a ^ col_b ^ 1;
        
        if (rank[root_a] == rank[root_b]) {
            rank[root_b]++;
        }
        
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    DSU dsu(n);
    string result;
    bool is_bipartite = true;
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        
        if (is_bipartite) {
            is_bipartite = dsu.union_sets(a, b);
        }
        
        result += is_bipartite ? '1' : '0';
    }
    
    cout << result << '\n';
    
    return 0;
}