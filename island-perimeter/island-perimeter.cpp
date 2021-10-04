class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int perimeter = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;
                // left
                if(j == 0 or grid[i][j-1] == 0) perimeter++;
                // right
                if(j == n-1 or grid[i][j+1] == 0) perimeter++;
                // up
                if(i == 0 or grid[i-1][j] == 0) perimeter++;
                // down
                if(i == m-1 or grid[i+1][j] == 0) perimeter++;
            }
        }
        
        return perimeter;
    }
};