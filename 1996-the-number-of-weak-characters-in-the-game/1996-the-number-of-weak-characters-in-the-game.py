class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        ans, st = [], []
        properties.sort(key=lambda x: (x[0], -x[1]))
        
        for p in properties:
            # print(f"st: {st}")
            while st and st[-1][0] < p[0] and st[-1][1] < p[1]:
                ans.append(st.pop())
            st.append(p)
        
        return len(ans)