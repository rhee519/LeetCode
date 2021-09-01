class Solution {
public:
    int dp[101][101][101];
    
    int getScore(vector<int>& boxes, int left, int right, int c) {
        if(left > right) return 0;
        
        if(dp[left][right][c]) { // already know
            return dp[left][right][c];
        }
        
        int res = (c+1)*(c+1) + getScore(boxes, left+1, right, 0);
        for(int mid = left+1; mid <= right; mid++) {
            if(boxes[left] == boxes[mid]) {
                res = max(res, getScore(boxes, left+1, mid-1, 0) + getScore(boxes, mid, right, c+1));
            }
        }
        
        return dp[left][right][c] = res;
    }
    int removeBoxes(vector<int>& boxes) {
        return getScore(boxes, 0, boxes.size()-1, 0);
    }
};