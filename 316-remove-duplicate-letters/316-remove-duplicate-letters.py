class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        last_occ = {ch: i for i, ch in enumerate(s)}
        st = []
        visited = set()
        
        for i in range(len(s)):
            if s[i] in visited:
                continue
            
            while st and s[i] < st[-1] and i < last_occ[st[-1]]:
                visited.remove(st.pop())
            
            st.append(s[i])
            visited.add(s[i])
        
        return "".join(st)