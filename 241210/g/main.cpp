#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Edge {
    int u, v;
    double length;
    bool operator<(const Edge& other) const {
        return length < other.length;
    }
};

struct Point {
    int x, y;
};

vector<int> parent, rank_;

void make_set(int v) {
    parent[v] = v;
    rank_[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_[a] < rank_[b])
            swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b])
            rank_[a]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<Point> trees(n);
    for (int i = 0; i < n; ++i) {
        cin >> trees[i].x >> trees[i].y;
    }

    vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double dx = trees[i].x - trees[j].x;
            double dy = trees[i].y - trees[j].y;
            double length = sqrt(dx * dx + dy * dy);
            edges.push_back({i, j, length});
        }
    }

    sort(edges.begin(), edges.end());

    parent.resize(n);
    rank_.resize(n);
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }

    int components = n;
    double max_length = 0.0;
    for (const Edge& e : edges) {
        if (components == k)
            break;
        if (find_set(e.u) != find_set(e.v)) {
            union_sets(e.u, e.v);
            components--;
            max_length = max(max_length, e.length);
        }
    }

    cout << fixed << setprecision(7) << max_length << endl;

    vector<int> team(n);
    int team_id = 1;
    for (int i = 0; i < n; ++i) {
        if (parent[i] == i) {
            for (int j = 0; j < n; ++j) {
                if (find_set(j) == i) {
                    team[j] = team_id;
                }
            }
            team_id++;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << team[i] << " ";
    }
    cout << endl;

    return 0;
}