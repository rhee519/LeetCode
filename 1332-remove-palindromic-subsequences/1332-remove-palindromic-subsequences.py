class Solution:
    def removePalindromeSub(self, s: str) -> int:
        l, r = 0, len(s)-1
        
        while l < r:
            if s[l] != s[r]:
                break
            l, r = l+1, r-1
        
        return 1 if l >= r else 2