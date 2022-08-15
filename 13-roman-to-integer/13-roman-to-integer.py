roman = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000
}

def isSub(curr: str, right: str) -> int:
    return (curr == 'I' and (right == 'V' or right == 'X')) or (curr == 'X' and (right == 'L' or right == 'C')) or (curr == 'C' and (right == 'D' or right == 'M'))

class Solution:
    def romanToInt(self, s: str) -> int:
        ans = 0
        right = ''
        for i in range(len(s)-1, -1, -1):
            val = roman[s[i]]
            if isSub(s[i], right):
                ans -= val
            else:
                ans += val
            right = s[i]
        
        return ans