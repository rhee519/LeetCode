class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        glass = [[0 for _ in range(query_row+1)] for _ in range(query_row+1)]
        glass[0][0] = poured
        
        for i in range(query_row):
            for j in range(i+1):
                if glass[i][j] > 1:
                    glass[i+1][j] += (glass[i][j]-1)/2.0
                    glass[i+1][j+1] += (glass[i][j]-1)/2.0
                    glass[i][j] = 1.0
        # print(glass)
        return min(glass[query_row][query_glass], 1)