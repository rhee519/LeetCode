class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        ans = 0
        pos = {}
        l, curr_sum = 0, 0 # curr_sum = sum(nums[l:r+1])
        
        for r in range(len(nums)):
            if nums[r] in pos:
                while l <= pos[nums[r]]:
                    curr_sum -= nums[l]
                    l += 1
            pos[nums[r]] = r
            curr_sum += nums[r]
            ans = max(ans, curr_sum)
        
        return ans