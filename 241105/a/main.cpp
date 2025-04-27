#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <tuple>

using namespace std;

// Custom hash function for pair<int, int>
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return ((size_t)p.first << 32) | p.second;
    }
};

struct DSU {
    vector<int> parent, rank;
    stack<tuple<int, int, int>> history;

    DSU(int n) : parent(n + 1), rank(n + 1, 1) {
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        while (parent[u] != u) {
            u = parent[u];
        }
        return u;
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;

        if (rank[u] < rank[v]) swap(u, v);
        history.emplace(v, parent[v], rank[u]);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
        return true;
    }

    void rollback() {
        auto [v, p, r] = history.top();
        history.pop();
        parent[v] = p;
        rank[parent[v]] = r;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> edges;
    unordered_map<pair<int, int>, int, PairHash> edge_to_index;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        edges.emplace_back(u, v);
        edge_to_index[{u, v}] = i;
    }

    vector<tuple<string, int, int>> operations(k);
    vector<bool> is_cut(m, false);

    for (int i = 0; i < k; ++i) {
        string type;
        int u, v;
        cin >> type >> u >> v;
        if (u > v) swap(u, v);
        operations[i] = {type, u, v};
        if (type == "cut") {
            is_cut[edge_to_index[{u, v}]] = true;
        }
    }

    DSU dsu(n);
    // First add all edges that are never cut
    for (int i = 0; i < m; ++i) {
        if (!is_cut[i]) {
            dsu.unite(edges[i].first, edges[i].second);
        }
    }

    stack<string> answers;
    // Process operations in reverse order
    for (int i = k - 1; i >= 0; --i) {
        auto [type, u, v] = operations[i];
        if (type == "ask") {
            answers.push(dsu.find(u) == dsu.find(v) ? "YES" : "NO");
        } else { // cut
            dsu.unite(u, v);
        }
    }

    // Output answers in original order
    while (!answers.empty()) {
        cout << answers.top() << '\n';
        answers.pop();
    }

    return 0;
}