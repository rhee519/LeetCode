class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        st = []  # st[i] == [ch, freq]
        for ch in s:
            if st and st[-1][0] == ch:
                st[-1][1] += 1
            else:
                st.append([ch, 1])
            if st[-1][1] == k:
                st.pop()
        
        # 'a'*3 == 'aaa'
        return ''.join(ch*freq for ch, freq in st)
        