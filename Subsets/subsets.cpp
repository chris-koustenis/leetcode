#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        const int N = nums.size();
        // There are 2^N possible subsets
        vector<int> subset;
        // Enumerate all subsets using the lower N bits of b
        for (int b = 0; b < (1 << N); ++b) {
            // Create a subset based on the bits of b
            subset.clear();
            for (int i = 0; i < N; ++i) {
                // Check if the i-th bit in b is set
                if (b & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            // Add the created subset to the answer
            answer.push_back(subset);
        }
        return answer;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.subsets(nums);
    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}