class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        ans = ['a'] * n
        k -= n
        i = len(ans) - 1
        while k:
            offset = min(k, 25)
            k -= offset
            # ans = ans[0:i] + chr(ord(ans[i]) + offset) + ans[i+1:]
            ans[i] = chr(ord(ans[i]) + offset)
            i -= 1
        
        return "".join(ans)