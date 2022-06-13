class Solution:
    def minimumTotal(self, tri: List[List[int]]) -> int:
        for i in range(1, len(tri)):
            tri[i][0] += tri[i-1][0]
            for j in range(1, i):
                tri[i][j] += min(tri[i-1][j-1], tri[i-1][j])
            tri[i][i] += tri[i-1][i-1]
        
        return min(tri[-1])