from typing import List

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        # Initialize closest_sum with the sum of the first three elements.
        closest_sum = nums[0] + nums[1] + nums[2]
        
        # Iterate over the list, taking one number at a time.
        for i in range(n - 2):
            left, right = i + 1, n - 1
            while left < right:
                current_sum = nums[i] + nums[left] + nums[right]
                # Update closest_sum if the current sum is closer to target.
                if abs(target - current_sum) < abs(target - closest_sum):
                    closest_sum = current_sum
                
                # Move pointers based on how current_sum compares to target.
                if current_sum < target:
                    left += 1
                elif current_sum > target:
                    right -= 1
                else:
                    # If current_sum equals target, it's the closest possible.
                    return current_sum
        
        return closest_sum
    
# Example usage:
if __name__ == "__main__":
    solution = Solution()
    nums = [-1, 2, 1, -4]
    target = 1
    print(solution.threeSumClosest(nums, target))  # Output: 2