#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            // Initialize closest to the sum of the first three elements and size
            int closest = nums[0] + nums[1] + nums[2];
            const int N = nums.size();
            // Iterate through the array
            for (int i = 0; i < N - 2; i++) {
                // Initialize left and right pointers
                int left = i + 1, right = N - 1;
                while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
                    if (abs(sum - target) < abs(closest - target)) {
                        closest = sum;
                    }
                    if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
            return closest;
        }
    };

// Example usage:
int main() {
    Solution solution;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = solution.threeSumClosest(nums, target);
    // Output the result
    return 0;
}