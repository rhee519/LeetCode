class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle.back().size();
        
        for(int i = 1; i < m; i++) {
            triangle[i-1].push_back(INT_MAX);
            triangle[i][0] += triangle[i-1][0];
            for(int j = 1; j < triangle[i].size(); j++) {
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        
        int ans = INT_MAX;
        for(int num: triangle.back()) {
            ans = min(ans, num);
        }
        
        return ans;
    }
};