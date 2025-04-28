#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct Segment {
    int l, r;
    Segment(int l, int r) : l(l), r(r) {}
    bool operator<(const Segment& other) const {
        return l < other.l;
    }
};

set<Segment> black_segments;

void add_black_segment(int L, int R) {
    if (L > R) return;
    auto it = black_segments.lower_bound(Segment(L, R));
    
    // Check previous segment for possible merge
    if (it != black_segments.begin()) {
        auto prev_it = prev(it);
        if (prev_it->r >= L - 1) {
            L = min(L, prev_it->l);
            R = max(R, prev_it->r);
            black_segments.erase(prev_it);
        }
    }
    
    // Merge with overlapping or adjacent segments
    while (it != black_segments.end() && it->l <= R + 1) {
        R = max(R, it->r);
        it = black_segments.erase(it);
    }
    
    black_segments.insert(Segment(L, R));
}

void add_white_segment(int L, int R) {
    if (L > R) return;
    auto it = black_segments.lower_bound(Segment(L, R));
    
    // Check previous segment for overlap
    if (it != black_segments.begin()) {
        auto prev_it = prev(it);
        if (prev_it->r >= L) {
            int prev_l = prev_it->l;
            int prev_r = prev_it->r;
            black_segments.erase(prev_it);
            if (prev_l < L) {
                black_segments.insert(Segment(prev_l, L - 1));
            }
            if (prev_r > R) {
                black_segments.insert(Segment(R + 1, prev_r));
            }
        }
    }
    
    // Check current and next segments for overlap
    while (it != black_segments.end() && it->l <= R) {
        int current_l = it->l;
        int current_r = it->r;
        it = black_segments.erase(it);
        if (current_r > R) {
            black_segments.insert(Segment(R + 1, current_r));
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        char c;
        int L, R;
        cin >> c >> L >> R;
        R = L + R - 1; // Convert length to R
        
        if (c == 'B') {
            add_black_segment(L, R);
        } else {
            add_white_segment(L, R);
        }
        
        int count = black_segments.size();
        int total_length = 0;
        for (const auto& seg : black_segments) {
            total_length += seg.r - seg.l + 1;
        }
        
        cout << count << " " << total_length << "\n";
    }
    
    return 0;
}