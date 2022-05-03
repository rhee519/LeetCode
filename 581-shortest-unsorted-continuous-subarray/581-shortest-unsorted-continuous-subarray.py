class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return 0
        
        left_max, right_min = nums[0], nums[-1]
        start_idx, end_idx = -1, -1
        
        for i in range(len(nums)):
            if left_max > nums[i]:
                end_idx = i
            left_max = max(left_max, nums[i])
        
        for i in range(len(nums)-1, -1, -1):
            if nums[i] > right_min:
                start_idx = i
            right_min = min(right_min, nums[i])
        
        if start_idx == -1 or end_idx == -1:
            return 0
        return end_idx-start_idx+1
                