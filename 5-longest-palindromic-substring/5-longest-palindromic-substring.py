class Solution:
    def getPalindrome(self, s: str, l: int, r: int) -> str:
        while 0 <= l and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return s[l+1:r]
            
    def longestPalindrome(self, s: str) -> str:
        ans = s[0]
        for i in range(len(s)):
            ans = max(ans, self.getPalindrome(s, i, i), self.getPalindrome(s, i, i+1), key=len)
        
        return ans
            