class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort() # O (n log n)
        n = len(nums)
        result = []
        # Dictionary to store the triplet.
        m = set()
        # Initialize closest_sum with the sum of the first three elements.
        # Iterate over the list, taking one number at a time.
        for i in range(n):
            if (i > 0) and (nums[i] == nums[i-1]):
                continue
            left, right = i + 1, n - 1
            while left < right:
                current_sum = nums[i] + nums[left] + nums[right]
                # Append triplet to result if current_sum equals 0.
                if current_sum == 0:
                    if (nums[i],nums[left],nums[right]) not in m:
                        result.append([nums[i], nums[left], nums[right]])
                        m.add((nums[i],nums[left],nums[right]))
                # Move pointers based on how current_sum compares to target.
                if current_sum < 0:
                    left += 1
                elif current_sum > 0: 
                    right -= 1
                else:
                    left += 1
                    right -= 1
        
        return result
    
# Time complexity: O(n^2)
# Space complexity: O(n)

