# 41. First Missing Positive

**Difficulty:** Hard

Given an unsorted integer array `nums`. Return the smallest positive integer that is not present in `nums`.

You must implement an algorithm that runs in `O(n)` time and uses `O(1)` auxiliary space.

## Examples

### Example 1

- **Input:** `nums = [1,2,0]`
- **Output:** `3`
- **Explanation:** The numbers in the range `[1,2]` are all in the array.

### Example 2

- **Input:** `nums = [3,4,-1,1]`
- **Output:** `2`
- **Explanation:** `1` is in the array but `2` is missing.

### Example 3

- **Input:** `nums = [7,8,9,11,12]`
- **Output:** `1`
- **Explanation:** The smallest positive integer `1` is missing.

## Constraints

- `1 <= nums.length <= 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`

## Solution

The solution typically involves **cyclic sort** or in-place modification.
1. Iterate through the array and place each number `x` at index `x - 1` (if `x` is between `1` and `n`).
2. Iterate through the modified array again. The first index `i` essentially where `nums[i] != i + 1` is the missing positive integer `i + 1`.
3. If all indices match, the answer is `n + 1`.

**Time Complexity:** $O(n)$
**Space Complexity:** $O(1)$