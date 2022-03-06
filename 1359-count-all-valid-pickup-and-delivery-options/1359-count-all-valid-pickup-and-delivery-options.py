class Solution:
    modulo = int(1e9+7)
    def countOrders(self, n: int) -> int:
        ans = 1
        for i in range(2, n+1):
            # (P1, ..., Pi-1, D1, ..., Di-1) + (Pi, Di)
            # ((2i-1, 2)) = (2i, 2)
            ans *= i*(2*i-1)
            ans %= self.modulo
        
        return ans