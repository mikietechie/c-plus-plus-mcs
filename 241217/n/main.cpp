#include <iostream>
#include <string>

using namespace std;

string find_min_suffix(const string &s) {
    int n = s.size();
    int min_pos = 0; // Start with first character as candidate
    
    for (int i = 1; i < n; ++i) {
        // Compare suffixes starting at i and min_pos
        int k = 0;
        while (i + k < n && min_pos + k < n && 
               s[i + k] == s[min_pos + k]) {
            k++;
        }
        if (i + k == n) continue; // i is shorter, can't be smaller
        if (min_pos + k == n || s[i + k] < s[min_pos + k]) {
            min_pos = i;
        }
    }
    
    return s.substr(min_pos);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    cout << find_min_suffix(s) << '\n';

    return 0;
}