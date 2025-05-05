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

vector<int> nearest_neighbor(vector<Point>& cities) {
    int n = cities.size();
    vector<int> tour;
    vector<bool> visited(n, false);
    
    int current = 0;
    tour.push_back(current);
    visited[current] = true;
    
    for (int i = 1; i < n; ++i) {
        double min_dist = 1e9;
        int next = -1;
        
        for (int j = 0; j < n; ++j) {
            if (!visited[j]) {
                double dist = distance(cities[current], cities[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    next = j;
                }
            }
        }
        
        tour.push_back(next);
        visited[next] = true;
        current = next;
    }
    
    return tour;
}

vector<int> two_opt(vector<Point>& cities, vector<int> tour) {
    int n = tour.size();
    bool improved = true;
    
    while (improved) {
        improved = false;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double delta = -distance(cities[tour[i]], cities[tour[i+1]])
                              -distance(cities[tour[j]], cities[tour[(j+1)%n]])
                              +distance(cities[tour[i]], cities[tour[j]])
                              +distance(cities[tour[i+1]], cities[tour[(j+1)%n]]);
                
                if (delta < -1e-9) {
                    reverse(tour.begin() + i + 1, tour.begin() + j + 1);
                    improved = true;
                }
            }
        }
    }
    
    return tour;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> cities(n);
    for (int i = 0; i < n; ++i) {
        cin >> cities[i].x >> cities[i].y;
    }
    
    vector<int> tour = nearest_neighbor(cities);
    tour = two_opt(cities, tour);
    
    for (int city : tour) {
        cout << city + 1 << " ";
    }
    cout << endl;
    
    return 0;
}