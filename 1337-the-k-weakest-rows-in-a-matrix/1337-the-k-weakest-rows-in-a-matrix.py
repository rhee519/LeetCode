class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        cnt = []
        
        for i in range(len(mat)):
            scnt = 0
            for s in mat[i]:
                if s == 1:
                    scnt += 1
                else:
                    break
            cnt.append((i, scnt))
        cnt.sort(key=lambda x: (x[1], x[0]))
        
        ans = []
        for i in range(k):
            ans.append(cnt[i][0])
        return ans