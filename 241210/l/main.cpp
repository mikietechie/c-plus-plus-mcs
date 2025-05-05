#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
};

double calculateDistance(const Point& a, const Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    vector<bool> inMST(n, false);
    vector<double> minDist(n, 1e18);
    vector<int> parent(n, -1);
    minDist[0] = 0;

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0.0, 0});

    double totalWeight = 0.0;

    while (!pq.empty()) {
        int u = pq.top().second;
        double dist = pq.top().first;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += dist;

        for (int v = 0; v < n; ++v) {
            if (u == v) continue;
            double d = calculateDistance(points[u], points[v]);
            if (!inMST[v] && d < minDist[v]) {
                minDist[v] = d;
                parent[v] = u;
                pq.push({d, v});
            }
        }
    }

    cout << fixed << setprecision(15) << totalWeight << endl;

    for (int i = 1; i < n; ++i) {
        if (parent[i] <= i) {
            cout << parent[i] + 1 << " " << i + 1 << endl;
        } else {
            cout << i + 1 << " " << parent[i] + 1 << endl;
        }
    }

    return 0;
}