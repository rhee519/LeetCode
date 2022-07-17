class Solution:
    def kInversePairs(self, _n: int, _k: int) -> int:
        modulo = int(10**9+7)
        memo = [[0 for _ in range(_k+1)] for _ in range(_n+1)]
        # memo[n][k] == arrays consist of 1~n & k inverse pairs
        
        # case1. n > k
        #   memo[n][k] = memo[n-1][0] + memo[n-1][1] + ... + memo[n-1][k]
        #                = memo[n][k-1] + memo[n-1][k]
        # case2. n <= k
        #   memo[n][k] = memo[n-1][k-n+1] + memo[n-1][k-n+2] + ... + memo[n-1][k]
        #              = memo[n-1][k-1] + memo[n-1][k] - memo[n-1][k-n] 
        
        # there exists one & only one array with no inverse pair
        for n in range(1, _n+1):
            memo[n][0] = 1
        
        for n in range(2, _n+1):
            for k in range(1, _k+1):
                if n > k:
                    memo[n][k] = (memo[n][k-1] + memo[n-1][k])%modulo
                else:
                    memo[n][k] = (memo[n][k-1] + memo[n-1][k] - memo[n-1][k-n])%modulo
        
        return memo[_n][_k]%modulo