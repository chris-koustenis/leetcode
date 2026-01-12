## 3Sum Closest

Given an integer array `nums` of length `n` and an integer `target`, find three integers in `nums` whose sum is closest to `target`.

Return the sum of the three integers. You may assume exactly one solution exists.

### Examples
- **Input:** `nums = [-1,2,1,-4]`, `target = 1`  
	**Output:** `2`  
	Closest sum: `-1 + 2 + 1 = 2`.

- **Input:** `nums = [0,0,0]`, `target = 1`  
	**Output:** `0`  
	Closest sum: `0 + 0 + 0 = 0`.

### Constraints
- `3 <= nums.length <= 500`
- `-1000 <= nums[i] <= 1000`
- `-10^4 <= target <= 10^4`