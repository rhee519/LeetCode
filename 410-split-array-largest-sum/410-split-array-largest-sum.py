class Solution:
    def is_valid(self, nums: List[int], m: int, limit: int) -> int:
        cuts, sum = 0, 0
        
        for num in nums:
            if num > limit:
                return False
            if sum + num <= limit:
                sum += num
            else:
                cuts += 1
                sum = num
            if cuts+1 > m:
                return False
        
        return True
        
    def splitArray(self, nums: List[int], m: int) -> int:
        low, high = max(nums), sum(nums)
        ans = low
        while low < high:
            mid = (low+high)//2
            if self.is_valid(nums, m, mid):
                ans, high = mid, mid
            else:
                ans, low = mid+1, mid+1
        
        return ans