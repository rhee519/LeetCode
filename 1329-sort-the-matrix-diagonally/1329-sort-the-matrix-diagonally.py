class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        diagonal = {}
        
        for i in range(m):
            for j in range(n):
                idx = i-j
                if idx not in diagonal:
                    diagonal[idx] = []
                diagonal[idx].append(mat[i][j])
        
        for idx in diagonal.keys():
            diagonal[idx].sort(key=lambda x: -x)
        
        # print(diagonal)
        
        for i in range(m):
            for j in range(n):
                idx = i-j
                mat[i][j] = diagonal[idx].pop()
        
        return mat