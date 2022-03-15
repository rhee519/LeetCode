class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        st, to_remove = [], {}
        ans = ""
        
        # check parentheses from forward
        for i in range(len(s)):
            if s[i] == '(':
                st.append(i)
            elif s[i] == ')':
                if st:
                    st.pop()
                else:
                    to_remove[i] = True
        while st:
            i = st.pop()
            to_remove[i] = True
        
        # remove parentheses
        for i in range(len(s)):
            if i not in to_remove:
                ans += s[i]
        
        return ans