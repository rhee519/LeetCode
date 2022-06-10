class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start, ans = 0, 0
        pos = {}
        
        for i in range(len(s)):
            if s[i] in pos and start <= pos[s[i]]:
                start = pos[s[i]]+1
            pos[s[i]] = i
            ans = max(ans, i-start+1)
            
        return ans