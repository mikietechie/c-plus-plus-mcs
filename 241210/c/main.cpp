#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

const double INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int S, T;
    cin >> S >> T;
    S--; T--; // converting to 0-based index

    vector<vector<pair<int, double>>> graph(N);
    for (int i = 0; i < M; ++i) {
        int u, v, p;
        cin >> u >> v >> p;
        u--; v--;
        double prob = p / 100.0;
        graph[u].emplace_back(v, prob);
        graph[v].emplace_back(u, prob); // since streets are bidirectional
    }

    vector<double> min_prob(N, INF);
    min_prob[S] = 1.0; // starting with probability 1 (safe)

    priority_queue<pair<double, int>> pq;
    pq.push({1.0, S});

    while (!pq.empty()) {
        double current_prob = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (u == T) break; // reached the university

        if (current_prob < min_prob[u]) continue; // already found a better path

        for (auto& edge : graph[u]) {
            int v = edge.first;
            double prob = edge.second;
            double new_prob = current_prob * prob;
            if (new_prob > min_prob[v]) { // we want to maximize the product (minimize the negative log)
                min_prob[v] = new_prob;
                pq.push({new_prob, v});
            }
        }
    }

    cout << fixed << setprecision(6) << (1.0 - min_prob[T]) * 100 << endl;

    return 0;
}