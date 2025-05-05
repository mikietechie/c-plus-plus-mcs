#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool can_merge(const vector<int>& a, const vector<int>& b) {
    int common = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == 1 && b[i] == 1) {
            common++;
            if (common > 1) return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<vector<int>, vector<int>>> students;
    for (int i = 0; i < k; ++i) {
        vector<int> knowledge(n);
        for (int j = 0; j < n; ++j) {
            cin >> knowledge[j];
        }
        students.emplace_back(knowledge, vector<int>{i + 1});
    }

    // Попытка объединения групп
    vector<pair<vector<int>, vector<int>>> merged_groups;
    for (const auto& student : students) {
        bool merged = false;
        for (auto& group : merged_groups) {
            if (can_merge(group.first, student.first)) {
                // Обновляем знания группы (логическое ИЛИ)
                for (int i = 0; i < n; ++i) {
                    group.first[i] |= student.first[i];
                }
                group.second.insert(group.second.end(), 
                                  student.second.begin(), student.second.end());
                merged = true;
                break;
            }
        }
        if (!merged) {
            merged_groups.push_back(student);
        }
    }

    // Вывод результатов
    cout << merged_groups.size() << endl;
    for (const auto& group : merged_groups) {
        cout << group.second.size();
        for (int student : group.second) {
            cout << " " << student;
        }
        cout << endl;
    }

    return 0;
}