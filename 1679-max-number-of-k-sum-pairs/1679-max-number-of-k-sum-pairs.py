class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        nums.sort()
        left, right = 0, len(nums)-1
        ans = 0
        while left < right:
            sum_pair = nums[left]+nums[right]
            if sum_pair == k:
                ans += 1
                left += 1
                right -= 1
            elif sum_pair < k:
                left += 1
            else: # sum_pair > k
                right -= 1
            
        return ans