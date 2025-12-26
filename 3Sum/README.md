## 3Sum

Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

The solution set must not contain duplicate triplets.

### Examples
- **Input:** `[-1,0,1,2,-1,-4]`  
	**Output:** `[[-1,-1,2],[-1,0,1]]`
	- `nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0`
	- `nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0`
	- `nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0`
	- Distinct triplets: `[-1,0,1]`, `[-1,-1,2]`

- **Input:** `[0,1,1]`  
	**Output:** `[]`  
	The only possible triplet does not sum to `0`.

- **Input:** `[0,0,0]`  
	**Output:** `[[0,0,0]]`  
	The only possible triplet sums to `0`.

### Constraints
- `3 <= nums.length <= 3000`
- `-10^5 <= nums[i] <= 10^5`