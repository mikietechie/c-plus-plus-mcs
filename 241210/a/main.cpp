// mike

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        dist[a][b] = min(dist[a][b], l); // Handle multiple edges between same pair
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int min_sum = INF;
    int capital = 1;

    for (int i = 1; i <= n; ++i) {
        int current_sum = 0;
        for (int j = 1; j <= n; ++j) {
            current_sum += dist[i][j];
        }
        if (current_sum < min_sum) {
            min_sum = current_sum;
            capital = i;
        }
    }

    cout << capital << " " << min_sum << endl;

    return 0;
}