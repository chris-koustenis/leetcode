from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]

        prev1, prev2 = 0, 0
        for n in nums:
            temp = prev1
            prev1 = max(prev2 + n, prev1)
            prev2 = temp

        return prev1
s = Solution()
print(s.rob([1,2,3,1]))  # Output: 4