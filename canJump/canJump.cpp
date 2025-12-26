// // You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// // Return true if you can reach the last index, or false otherwise.
// #include <vector>
// #include <iostream>

// using namespace std;

// class Solution {
// public:
//     int canJumpHelper(int position, const vector<int>& nums, const int &N, vector<int>& memo) {
//         // Base case: if we have reached the last index
//         if(nums[position] == 0 && position != N - 1){
//             memo[position] = 0;
//             return memo[position];
//         }
//         if (position == N - 1) {
//             return true;
//         }else{
//             // Check memoization
//             if (memo[position] != -1) {
//                 return memo[position];
//             }

//             int furthestJump = min(position + nums[position], static_cast<int>(N - 1)); // Ensure we don't go out of bounds
//             for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++) {
//                 // Recursive call to check if we can reach the end from nextPosition
//                 if (canJumpHelper(nextPosition, nums, N, memo)) {
//                     memo[position] = 1; // Mark as reachable
//                     return memo[position];
//                 }
//             }

//             memo[position] = 0; // Mark as not reachable
//             return memo[position];
//         }
//     }
//     bool canJump(vector<int>& nums) {
//         //Base case: if the size of nums is 1, we are already at the last index
//         if(nums.size() == 1) return true;
//         const int N = nums.size();
//         vector<int> memo;
//         memo.resize(N, -1);
//         memo[N-1] = 1; // last index is always reachable from itself
//         if(canJumpHelper(0, nums, N, memo) == 1){
//             return true;
//         }else return false;
//     }
// };
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        //Base case: if the size of nums is 1, we are already at the last index
        if(nums.size() == 1) return true;
        const int N = nums.size();

        int lastZeroPos = -1;
        for(int i = N - 2; i >= 0; i--){
                if(nums[i] == 0 && lastZeroPos == -1){
                    lastZeroPos = i;
                }else{
                    // check if we can jump over the zero
                    if(nums[i] > lastZeroPos - i){
                        lastZeroPos = -1; // reset lastZeroPos
                    }
                }
        }
        if(lastZeroPos != -1) return false; // there is a zero that cannot be jumped over
        
        return true;
    }
};


int main() {
    Solution s;
    std::vector<std::vector<int>> nums = {{2,3,1,1,4}, {3,2,1,0,4}};
    for (auto testcase : nums)
        std::cout << s.canJump(testcase) << std::endl;
    return 0;
}