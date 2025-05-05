// author mike

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> dist(N, vector<int>(N, INF));

    for (int i = 0; i < N; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int weight;
            cin >> weight;
            if (weight != -1 && i != j) {
                dist[i][j] = weight;
            }
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int diameter = 0;
    vector<int> eccentricities(N, 0);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dist[i][j] != INF && dist[i][j] > eccentricities[i]) {
                eccentricities[i] = dist[i][j];
            }
        }
        if (eccentricities[i] > diameter) {
            diameter = eccentricities[i];
        }
    }

    int radius = *min_element(eccentricities.begin(), eccentricities.end());

    cout << diameter << "\n" << radius << endl;

    return 0;
}