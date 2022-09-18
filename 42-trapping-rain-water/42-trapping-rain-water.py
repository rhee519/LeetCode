class Solution:
    def trap(self, heights: List[int]) -> int:
        n = len(heights)
        left, right = [heights[0]] + [0]*(n-1), [0]*(n-1) + [heights[-1]]
        ans = 0
        
        for i in range(1, n): # left
            left[i] = max(left[i-1], heights[i])
        for i in range(n-2, -1, -1): # right
            right[i] = max(heights[i], right[i+1])
        
        # print(f"left: {left}")
        # print(f"right: {right}")
        # print(f"heights:{heights}")
        for i in range(n):
            ans += max(min(left[i], right[i])-heights[i], 0)
        
        return ans