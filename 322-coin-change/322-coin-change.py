class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        memo = [0]+[-1 for _ in range(amount)]
        
        for i in range(1, amount+1):
            for coin in coins:
                if i-coin < 0 or memo[i-coin] == -1:
                    continue
                if memo[i] == -1 or memo[i] > memo[i-coin]+1:
                    memo[i] = memo[i-coin]+1
        
        return memo[amount]