class Solution:
    def brokenCalc(self, startValue: int, target: int) -> int:
        
        if startValue >= target:
            return startValue - target
        
        if target % 2: # target is odd
            return self.brokenCalc(startValue, target+1) + 1
        
        # target is even
        ans = 1000000000
        cnt = 0
        while target % 2 == 0:
            target //= 2
            cnt += 1
            ans = min(
                ans,
                self.brokenCalc(startValue, target) + cnt
            )
            if target <= startValue:
                break
        
        return ans