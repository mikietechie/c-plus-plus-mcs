#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string cells;
    cin >> cells;
    // Directions the rabbit can jump
    vector<int> jumps = {2, 3, 6};
    // BFS setup
    queue<tuple<int, int, int, vector<int>>> q; // (current position, jumps made, grass count, path)
    vector<bool> visited(n + 1, false);
    vector<int> path;
    // Start from cell 1
    q.push({1, 0, 0, {1}});
    visited[1] = true;
    int min_jumps = -1;
    int max_grass = -1;
    vector<int> best_path;
    while (!q.empty())
    {
        auto [current, jumps_made, grass_count, current_path] = q.front();
        q.pop();
        // If we reach the last cell
        if (current == n)
        {
            if (min_jumps == -1 || jumps_made < min_jumps ||
                (jumps_made == min_jumps && grass_count > max_grass))
            {
                min_jumps = jumps_made;
                max_grass = grass_count;
                best_path = current_path;
            }
            continue;
        }
        // Explore possible jumps
        for (int jump : jumps)
        {
            int next = current + jump;
            if (next <= n && !visited[next] && cells[next - 1] != 'w')
            {
                visited[next] = true;
                vector<int> new_path = current_path;
                new_path.push_back(next);
                int new_grass_count = grass_count + (cells[next - 1] == 'w' ? 1 : 0);
                q.push({next, jumps_made + 1, new_grass_count, new_path});
            }
        }
    }
    if (min_jumps == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << min_jumps << " " << max_grass << endl;
        for (int cell : best_path)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}