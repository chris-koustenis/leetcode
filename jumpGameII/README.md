# Jump Game II

Given a 0-indexed integer array `nums` of length `n`, you start at index `0`.

Each element `nums[i]` represents the maximum length of a forward jump from index `i`. From index `i`, you can jump to any index `i + j` where:

- `0 <= j <= nums[i]`
- `i + j < n`

Return the minimum number of jumps needed to reach index `n - 1`. The test cases are generated such that you can reach index `n - 1`.

## Examples

### Example 1

```
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

### Example 2

```
Input: nums = [2,3,0,1,4]
Output: 2
```

## Constraints

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 1000`
- It is guaranteed that you can reach `nums[n - 1]`.