class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        ans = []
        if k == 0:
            for i in range(1, 10):
                ans.append(str(i) * n)
            return ans
        
        q = deque([str(i) for i in range(1, 10)])
        while q:
            num = q.popleft()
            lower, upper = int(num[-1])-k, int(num[-1])+k
            if 0 <= lower < 10:
                lstr = num+str(lower)
                if len(lstr) == n:
                    ans.append(lstr)
                else:
                    q.append(lstr)
            if 0 <= upper < 10:
                ustr = num+str(upper)
                if len(ustr) == n:
                    ans.append(ustr)
                else:
                    q.append(ustr)
                    
        return ans