#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {   
        const int N = nums.size();
        int farthest = 0;
        int min_jumps = 0;
        int current_end = 0;
        for (int pos = 0; pos < N-1; pos++)
        {
            farthest = max(farthest, pos + nums[pos]);
    
            if (farthest >= N - 1)
            {
               return ++min_jumps;    
            }
            if(pos == current_end){
                min_jumps++;
                current_end = farthest;
            }
        }
        return min_jumps;
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