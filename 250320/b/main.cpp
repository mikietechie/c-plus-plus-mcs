#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<Point> cities(n);
    for (int i = 0; i < n; ++i) {
        cin >> cities[i].x >> cities[i].y;
    }
    
    vector<bool> visited(n, false);
    visited[0] = true;
    vector<int> path = {1};
    double remaining = k;
    int current = 0;
    
    while (true) {
        double min_dist = 1e9;
        int next = -1;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                double dist = distance(cities[current], cities[i]);
                if (dist < min_dist) {
                    min_dist = dist;
                    next = i;
                }
            }
        }
        
        if (next == -1 || remaining < min_dist) break;
        
        remaining -= min_dist;
        visited[next] = true;
        path.push_back(next + 1);
        current = next;
    }
    
    cout << path.size() << endl;
    for (int city : path) {
        cout << city << " ";
    }
    cout << endl;
    
    return 0;
}