class Solution:
    def dp(self, nums: List[int], target: int, memo: List[int]) -> int:
        """
        nums: sorted list
        """
        if target < 0:
            return 0
        if target == 0:
            return 1
        if target == 1:
            return 1 if nums[0] == 1 else 0
        
        if memo[target] >= 0: 
            return memo[target]
        
        memo[target] = 0
        for num in nums:
            if num > target:
                break
            memo[target-num] = self.dp(nums, target-num, memo)
            memo[target] += memo[target-num]
                
        memo[target] = max(memo[target], 0)
        return memo[target]
    
    def combinationSum4(self, nums: List[int], target: int) -> int:
        memo = [-1 for _ in range(target+1)]
        memo[0] = 1
        nums.sort()
        memo[target] = self.dp(nums, target, memo)
#         print(f'nums: {nums}, target: {target}')
#         print(f'memo: {memo}')
        
        return memo[target]