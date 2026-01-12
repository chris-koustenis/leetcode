#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            while(nums[i]>=1 && nums[i]<=n && nums[i]!=nums[nums[i]-1]) swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<n;i++) if(nums[i]!=i+1) return i+1;
        return n+1;
    }
};

int main() {
    // Example usage:
    Solution sol;
    vector<int> nums = {3, 4, -1, 1};
    int result = sol.firstMissingPositive(nums);
    // result should be 2
    cout << "First missing positive: " << result << endl;
    vector<int> nums2 = {100000, 3, 4000, 2, 15, 1, 99999};// 100000,3,4000,2,15,999999
    result = sol.firstMissingPositive(nums2);
    // result should be 4
    cout << "First missing positive: " << result << endl;

    return 0;
}