class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        if not s:
            return 0
        if s == "()":
            return 1
        
        cnt = 0
        for i in range(len(s)):
            if s[i] == "(":
                cnt += 1
            else:
                cnt -= 1
            if cnt == 0:
                break
        
        
        if i == len(s)-1:
            # s == "(...)"
            return 2 * self.scoreOfParentheses(s=s[1:-1])
        
        # s == "(...)(...)"
        return self.scoreOfParentheses(s=s[0:i+1]) + self.scoreOfParentheses(s=s[i+1:])