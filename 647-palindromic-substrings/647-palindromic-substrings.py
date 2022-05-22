class Solution:
    def isPalindrome(self, s: str) -> bool:
        for i in range(len(s)//2):
            if s[i] != s[-i-1]:
                return False
        return True
    
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        cnt = 0
        
        # memo[i][j] = isPalindrome(s[i:j])
        memo = [[False for _ in range(n+1)] for _ in range(n)]
        for i in range(n):
            memo[i][i] = True       # empty string
            memo[i][i+1] = True     # single letter
            cnt += 1
        
        for l in range(2, n+1):
            for i in range(n-l+1): 
                # check if s[i:i+l] is a palindrome
                # print(f's[{i}:{i+l}]: {s[i:i+l]}')
                memo[i][i+l] = s[i] == s[i+l-1] and memo[i+1][i+l-1]
                if memo[i][i+l]:
                    cnt += 1
        
        return cnt