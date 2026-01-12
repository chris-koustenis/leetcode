#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    int N;
    void backtrack(int index, vector<int>& nums, vector<vector<int>>& ans, int N) {
        if (index == N) {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < N; ++i) {
            swap(nums[index], nums[i]);
            backtrack(index + 1, nums, ans, N);
            swap(nums[index], nums[i]); // backtrack
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        N = nums.size();
        backtrack(0, nums, ans, N);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.permute(nums);
    for (const auto& permutation : result) {
        cout << "[";
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}