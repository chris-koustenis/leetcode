#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
private:
    //Trying  approach BOTTOM UP
    int jump_helper(const vector<int> &nums, int start, int jumps, const int &N, vector<int> &memo)
    {   
        if (start >= N - 1)
        {
            return jumps;
        }
        if (memo[start] != -1)
        {
            return jumps + memo[start];
        }

        int min_jumps = INT_MAX;
        int max_jump = nums[start];
        for (int jump_length = 1; jump_length <= max_jump; ++jump_length)
        {
            int next_pos = start + jump_length;
            if (next_pos < N)
            {
                int current_jumps = jump_helper(nums, next_pos, jumps + 1, N, memo);
                min_jumps = min(min_jumps, current_jumps);
            }
        }
        memo[start] = min_jumps - jumps; // Store only the additional jumps needed from this position
        return min_jumps;
    }

public:
    int jump(vector<int> &nums)
    {   
        const int N = nums.size();
        if (N == 1)
        {
            return 0;
        }
        vector<int> memo(N, -1); // N memoulation memole
        return jump_helper(nums, 0, 0, N, memo);
    }
};


int main()
{
    Solution s;
    vector<vector<int>> nums = {{2, 3, 1, 1, 4}, {2, 3, 0, 1, 4}};
    for (auto num : nums)
        cout << s.jump(num) << endl;
    return 0;
}