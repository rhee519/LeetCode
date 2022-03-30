class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows, cols = len(matrix), len(matrix[0])
        low, high = 0, rows*cols
        mid = (low+high)//2
        
        while low < high:
            num = matrix[mid//cols][mid%cols]
            if num == target:
                return True
            elif num < target:
                low = mid+1
            else:
                high = mid
            mid = (low+high)//2
        
        # return matrix[mid//cols][mid%cols] == target
        return False
        