class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        dp = [0]*(max(nums)+1)
        for num in nums:
            dp[num] += num
        for i in range(2, len(dp)):
            dp[i] = max(dp[i-2]+dp[i], dp[i-1])
        return dp[-1]