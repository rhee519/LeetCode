def nCr(n: int, r: int) -> int:
    return math.factorial(n) // (math.factorial(r) * math.factorial(n-r))

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return nCr(m+n-2, m-1)