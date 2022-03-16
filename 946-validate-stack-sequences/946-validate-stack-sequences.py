class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        st = []
        i, j = 0, 0
        while i < len(pushed) and j < len(popped):
            if st and st[-1] == popped[j]:
                st.pop()
                j += 1
            else:
                st.append(pushed[i])
                i += 1
            
        while st:
            if(st.pop() != popped[j]):
                return False
            j += 1
        
        return True