class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        ans, st = [], []
        properties.sort(key=lambda x: (x[0], -x[1]))
        
        for a, d in properties:
            # print(f"st: {st}")
            while st and st[-1] < d:
                ans.append(st.pop())
            st.append(d)
        
        return len(ans)