class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        idx = len(nums)-1
        while True:
            idx -= 1
            if idx < 0:
                break
            left, right = nums[idx], nums[idx+1]
            if left < right:
                break
        
        if idx == -1: # last permutation
            nums.reverse()
            return
        
        # only need to permute nums[idx:]
        jdx = len(nums)-1
        while nums[idx] >= nums[jdx]:
            jdx -= 1
        
        nums[idx], nums[jdx] = nums[jdx], nums[idx]
        # reverse nums[idx+1:] in place
        i, j = idx+1, len(nums)-1
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1
        
        return
