#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = nums.size();
        vector<int> answer(N, 1);
        for(int j = 1 ; j < N; ++j){
            answer[j] = nums[j-1] * answer[j-1];
        }
        int buildup = 1;
        for(int j = N - 2; j >= 0; --j){
            buildup *= nums[j+1];
            answer[j] *= buildup ;
        }        
        return answer;
    }
};

int main() {
    // Example usage:
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = sol.productExceptSelf(nums);
    // result should be {24, 12, 8, 6}
    cout << "Product of array except self: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}