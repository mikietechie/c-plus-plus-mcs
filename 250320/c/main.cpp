#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    map<vector<int>, vector<int>> groups;
    for (int i = 1; i <= k; ++i) {
        vector<int> topics(n);
        for (int j = 0; j < n; ++j) {
            cin >> topics[j];
        }
        groups[topics].push_back(i);
    }
    
    cout << groups.size() << endl;
    for (auto& [topics, students] : groups) {
        cout << students.size();
        for (int student : students) {
            cout << " " << student;
        }
        cout << endl;
    }
    
    return 0;
}