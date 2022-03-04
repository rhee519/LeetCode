class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        glass = [0] * (query_row+1)
        glass[0] = poured
        
        for i in range(1, len(glass)):
            for j in range(i, -1, -1): # from j=i to j=0
                glass[j] = max(glass[j]-1, 0)/2 + max(glass[j-1]-1, 0)/2
        
        return min(glass[query_glass], 1)