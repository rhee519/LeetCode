class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        letter = {}
        for ch in s:
            if ch not in letter:
                letter[ch] = 1
            else:
                letter[ch] += 1
        
        for ch in t:
            if ch not in letter or letter[ch] == 0:
                return False
            letter[ch] -= 1
        
        return True