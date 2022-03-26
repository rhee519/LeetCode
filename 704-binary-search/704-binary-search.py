class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)
        mid = (left+right)//2
        
        while left < right:
            if nums[mid] < target:
                left = mid+1
            elif nums[mid] > target:
                right = mid
            else:
                break

            mid = (left+right)//2
        
        return mid if mid in range(len(nums)) and nums[mid] == target else -1