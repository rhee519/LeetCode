class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        arr = []
        for row in matrix:
            for num in row:
                arr.append(num)
        
        arr.sort()
        return arr[k-1]
        