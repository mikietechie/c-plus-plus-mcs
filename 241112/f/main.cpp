#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

struct Event {
    int pos;
    int delta;
    bool operator<(const Event& other) const {
        return pos < other.pos;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<Event> events;
    map<int, int> active_segments;
    
    int black_count = 0;
    long long black_total_length = 0;
    
    for (int i = 0; i < N; ++i) {
        char color;
        int start, length;
        cin >> color >> start >> length;
        int end = start + length;
        
        if (color == 'B') { // Black segment
            events.push_back({start, 1});
            events.push_back({end, -1});
        } else { // White segment
            events.push_back({start, -1});
            events.push_back({end, 1});
        }
        
        // Sort events by position
        sort(events.begin(), events.end());
        
        // Process events to update active segments
        int current_coverage = 0;
        int prev_pos = -1e9;
        black_count = 0;
        black_total_length = 0;
        
        for (const auto& event : events) {
            if (current_coverage > 0 && prev_pos != event.pos) {
                black_total_length += event.pos - prev_pos;
            }
            
            current_coverage += event.delta;
            
            if (current_coverage > 0 && event.delta > 0 && 
                (prev_pos == -1e9 || current_coverage - event.delta <= 0)) {
                black_count++;
            }
            if (current_coverage <= 0 && event.delta < 0 && 
                current_coverage - event.delta > 0) {
                black_count--;
            }
            
            prev_pos = event.pos;
        }
        
        cout << black_count << " " << black_total_length << "\n";
    }
    
    return 0;
}