class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ans = []
        if len(nums) == 0:
            return ans
        
        start = end = nums[0]
        for i in range(1, len(nums)):
            if nums[i-1] + 1 == nums[i]:
                end = nums[i]
            else:
                if start == end:
                    ans.append(str(start))
                else:
                    ans.append(f'{start}->{end}')
                start = end = nums[i]
        
        if start == end:
            ans.append(str(start))
        else:
            ans.append(f'{start}->{end}')
            start = end = nums[i]
        
        return ans