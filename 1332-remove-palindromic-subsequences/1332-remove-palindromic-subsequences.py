class Solution:
    def removePalindromeSub(self, s: str) -> int:
        q = deque(s)
        
        while len(q) > 1 and q[0] == q[-1]:
            q.popleft()
            q.pop()
        
        return 1 if len(q) <= 1 else 2