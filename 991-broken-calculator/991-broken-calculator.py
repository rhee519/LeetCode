class Solution:
    def brokenCalc(self, startValue: int, target: int) -> int:
        cnt = 0
        while startValue < target:
            if target % 2: # target is odd
                target += 1
            else: # target is even
                target //= 2
            cnt += 1
                
        return startValue - target + cnt