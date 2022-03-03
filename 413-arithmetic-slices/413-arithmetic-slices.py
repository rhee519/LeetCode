class Solution:
    @staticmethod
    def numOfSubarrays(n: int) -> int:
        # (n-3)+1 + (n-4)+1 + ... + (n-n)+1 subarrays exist
        return (n-1)*(n-2)//2 if n > 0 else 0
        
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        diff = []
        for i in range(1, len(nums)):
            diff.append(nums[i]-nums[i-1])
        # print(diff)
        
        memo = []
        cnt = 2
        for i in range(1, len(diff)):
            if diff[i] == diff[i-1]:
                cnt += 1
            else:
                if cnt > 2:
                    memo.append(cnt)
                cnt = 2
        
        if cnt > 2:
            memo.append(cnt)
        
        ans = 0
        for n in memo:
            ans += self.numOfSubarrays(n)
        return ans