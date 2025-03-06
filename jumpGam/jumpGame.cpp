#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
private:
    static vector<int> arr;

    int jump_helper(vector<int> &nums, int start, int jumps, const int &N)
    {   
        // BASE CASE
        if (start == N - 1)
        {
            return 0;
        }

        int min_jumps = INT_MAX;
        // MEMOIZATION
        if (arr[start] != -1)
        {
            return arr[start];
        }

        // RECURSIVE CASE
        for (int i = 1; i <= nums[start] && i + start < N ; i++)
        {
            min_jumps = min(min_jumps,  jump_helper(nums, start + i, jumps + 1, N));
        }
        arr[start] = min_jumps + 1;
        return arr[start];
    }

public:
    int jump(vector<int> &nums)
    {   
        const int N = nums.size();
        if (N == 1)
        {
            return 0;
        }
        return jump_helper(nums, 0, 0, N);
    }
};


vector<int> Solution::arr(1001, -1);

int main()
{
    Solution s;
    vector<vector<int>> nums = {{2, 3, 1, 1, 4}, {2, 3, 0, 1, 4}};
    for (auto num : nums)
        cout << s.jump(num) << endl;
    return 0;
}