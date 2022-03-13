class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        par = {')': '(', '}': '{', ']': '['}
        for i in range(len(s)):
            if s[i] == '(' or s[i] == '{' or s[i] == '[':
                st.append(s[i])
            else:
                if st and st[-1] == par[s[i]]:
                    st.pop()
                else:
                    return False
        
        return len(st) == 0