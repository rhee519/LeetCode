class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        m, n = len(matrix), len(matrix[0])
        self.psum = [[0 for _ in range(n+1)]]
        for row in matrix:
            self.psum.append([0]+row)
        for i in range(1, m+1):
            for j in range(1, n+1):
                self.psum[i][j] += self.psum[i][j-1]
        for j in range(1, n+1):
            for i in range(1, m+1):
                self.psum[i][j] += self.psum[i-1][j]
#         print(self.psum)
        
    def sumRegion(self, r1: int, c1: int, r2: int, c2: int) -> int:
        return self.psum[r2+1][c2+1] - self.psum[r2+1][c1] - self.psum[r1][c2+1] + self.psum[r1][c1]


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)