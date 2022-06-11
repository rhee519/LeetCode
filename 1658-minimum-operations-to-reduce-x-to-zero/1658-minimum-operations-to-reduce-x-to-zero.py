class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        max_len = 0
        found = False
        l, curr_sum = 0, 0 # curr_sum = sum(nums[l:r+1])
        target = sum(nums)-x
        
        for r in range(len(nums)):
            curr_sum += nums[r]
            while l <= r and curr_sum > target:
                curr_sum -= nums[l]
                l += 1
            if curr_sum == target:
                found = True
                max_len = max(max_len, r-l+1)
        
        return len(nums)-max_len if found else -1