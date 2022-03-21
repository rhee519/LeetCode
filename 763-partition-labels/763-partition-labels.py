class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        ans = []
        last_occ = {ch: i for i, ch in enumerate(s)}
        
        partition = set()
        idx = 0
        size = 0
        for i in range(len(s)):
            partition.add(s[i])
            size += 1
            idx = max(idx, last_occ[s[i]])
            if i == idx:
                ans.append(size)
                partition.clear()
                size = 0
        
        return ans