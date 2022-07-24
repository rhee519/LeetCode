class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for i in range(len(matrix)):
            if matrix[i][-1] < target:
                continue
            elif target < matrix[i][0]:
                break
            
            pos = bisect_left(matrix[i], target)
            # print(f'matrix[{i}][{pos}] = {matrix[i][pos]}')
            if matrix[i][pos] == target:
                return True
        
        return False