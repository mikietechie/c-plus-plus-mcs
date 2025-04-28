#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_sum_subsequence(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return max(0, nums[0]);
    
    int prev_prev = max(0, nums[0]);
    int prev = max(prev_prev, nums[1]);
    
    for (int i = 2; i < n; ++i) {
        int current = max(prev, prev_prev + nums[i]);
        prev_prev = prev;
        prev = current;
    }
    
    return prev;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    cout << max_sum_subsequence(nums) << '\n';
    
    return 0;
}