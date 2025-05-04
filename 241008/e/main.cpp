#include <iostream>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

unsigned int reverse_bits(unsigned int x) {
    x = ((x >> 1) & 0x55555555) | ((x & 0x55555555) << 1);
    x = ((x >> 2) & 0x33333333) | ((x & 0x33333333) << 2);
    x = ((x >> 4) & 0x0F0F0F0F) | ((x & 0x0F0F0F0F) << 4);
    x = ((x >> 8) & 0x00FF00FF) | ((x & 0x00FF00FF) << 8);
    x = (x >> 16) | (x << 16);
    return x;
}

int min_operations(unsigned int n) {
    if (n == 0) return 0;
    
    unordered_map<unsigned int, int> visited;
    queue<pair<unsigned int, int>> q;
    q.push({0, 0});
    visited[0] = 0;

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();

        if (current == n) {
            return steps;
        }

        // Operation 1: Add 1
        unsigned int next_num = (current + 1) % (1ULL << 32);
        if (visited.find(next_num) == visited.end() || steps + 1 < visited[next_num]) {
            visited[next_num] = steps + 1;
            q.push({next_num, steps + 1});
        }

        // Operation 2: Reverse bits
        unsigned int reversed_num = reverse_bits(current);
        if (visited.find(reversed_num) == visited.end() || steps + 1 < visited[reversed_num]) {
            visited[reversed_num] = steps + 1;
            q.push({reversed_num, steps + 1});
        }
    }
    return -1;
}

int main() {
    unsigned int n;
    cin >> n;
    cout << min_operations(n) << endl;
    return 0;
}